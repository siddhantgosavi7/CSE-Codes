#include<iostream>
#include<vector>
#include<string>
#include <cmath>
using namespace std;


int main() {
    vector<int> DATA;
    string Data;

    cout << "Enter the DATA: ";
    cin >> Data;

    for(char x: Data) {
        if(x == '0') {
            DATA.push_back(0);
        } else if (x == '1') {
            DATA.push_back(1);
        } else {
            cout << "Invalid Input" << endl;
            return 0;
        }
        
    }
    
    //string DATA = "1101";

    int m = DATA.size();
    int k = 0;
    int n = 0;

    for(int i=0; i<10; i++) {
        if(pow(2, i) >= m + i +1) {
            k = i;
            break;
        }
    }

    n = m+k;
    cout << "DATA: ";
    for(int i=0; i<m; i++) {
        cout << DATA[i];
    }
    cout << "  m: " << m;
    cout << "  k: " << k;
    cout << "  n: " << n << endl;


    vector<int> DataCodeWord(n, -1);

    int j = m-1;
    for(int i=0; i<n; i++) {

        int position = i + 1;

        // Skip parity positions: 1, 2, 4, 8...
        if ((position & (position - 1)) == 0) {
            continue;
        }


        if(DATA[j--] == 1) {
            DataCodeWord[n-1-i] = 1;
        } else {
            DataCodeWord[n-1-i] = 0;
        }

        cout << DataCodeWord[n-1-i] << " " << pow(2, i) << " " << i +1<< endl;
    }

    cout << "DataCodeWord: ";
    for(int i=0; i<n; i++) {
        cout << DataCodeWord[i] << " ";

    }
    cout << endl;
    
    vector<vector<int>> ParityBits(n+1, vector<int>(k, -1));
    int t = 0;
    for(int i=0; i<=n; i++) {
        t = i;
        for(int j=k-1; j>=0; j--) {
            if(pow(2, j) <= t) {
                ParityBits[i][k-1-j] = 1;
                t -= pow(2, j);
            } else {
                ParityBits[i][k-1-j] = 0;
            }
        }
    }

    /*cout << endl << "ParityBits: " << endl;
    for(int i=0; i<=n; i++) {
        for(int j=0; j<k; j++) {
            cout << ParityBits[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;*/

    for(int i=0; i<k; i++) {
        int parity = 0;
        for(int j=0; j<=n; j++) {
            if(!parity && ParityBits[j][i] == 1) {parity = 1; continue;}

            if(ParityBits[j][i] == 1) {
                ParityBits[0][i] ^= DataCodeWord[n-j];
                //cout << "#" << ParityBits[0][i] << " " << DataCodeWord[n-j] << "  ";
            } 
        }
    }

    cout << "ParityBits: ";
    for(int i=0; i<k; i++) {
        cout << "P" << i+1 << ": ";
        cout << ParityBits[0][i] << " ";
    } 
    cout << endl;

    for(int i=0; i<=k; i++) {

        int position = i + 1;

        // parity positions: 1, 2, 4, 8...
        if ((position & (position - 1)) == 0) {
            DataCodeWord[n-1-i] = ParityBits[0][i];
            cout << "#" << DataCodeWord[n-1-i] << " " << i << "  ";
        }

    } cout << endl;

    cout << "DataCodeWord: ";
    for(int i=0; i<n; i++) {
        cout << DataCodeWord[i];
    }

    cout << endl;
    return 0;
}