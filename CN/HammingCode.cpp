#include<iostream>
#include<vector>
#include<string>
#include <cmath>
using namespace std;


int main() {

    /*cout << "Enter Numbers of Blocks: ";
    cin >> n;
    vector<string> Bits(n, "");

    cin >> Bits[i];

    for(int i=0; i<n; i++) {
        for(int j=i+1; j<n; j++) {

        }
    }
    */
    
    string DATA = "1101";

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
    cout << "DATA: " << DATA;
    cout << " m: " << m;
    cout << " k: " << k;
    cout << " n: " << n << endl;


    vector<char> DataCodeWord;

    int j = 0;
    for(int i=n-1; i>=0; i--) {
        DataCodeWord.push_back('x');

        if(n-1-i != pow(2, i)) {
            DataCodeWord[i] = DATA[j++];
        } 
        cout << DataCodeWord[i] << " " << pow(2, i) << endl;
    }
    for(int i=0; i<n; i++) {
        //cout << DataCodeWord[i] << " ";
    }

    return 0;
}