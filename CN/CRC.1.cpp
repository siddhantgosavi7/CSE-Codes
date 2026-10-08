#include<iostream>
#include<vector>
#include<string>
#include <cmath>
using namespace std;


int main() {
    vector<int> DATA;
    vector<int> Divisor;
    string Data, Div;

    cout << "Enter the DATA: ";
    cin >> Data;
    cout << "Enter Divisor: ";
    cin >> Div;

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

    for(char x: Div) {
        if(x == '0') {
            Divisor.push_back(0);
        } else if (x == '1') {
            Divisor.push_back(1);
        } else {
            cout << "Invalid Input" << endl;
            return 0;
        }
        
    }

    vector<int> Temp = DATA;

    int n = Divisor.size();

    cout << "DATA bits: ";
    for(int x : DATA) {
        cout << x;
    }
    cout << endl << "Divisor: ";

    for(int x : Divisor) {
        cout << x;
    }
    

    for(int i=0; i<n-1; i++) {
        Temp.push_back(0);
    }

    cout << "\nDATA after 0's appending: ";
    for(int x : Temp) {
        cout << x;
    }
    cout << endl;


    int i = 0;
    
    cout << " ";


    cout << endl << endl;

    while(i <= Temp.size() - n) {

        if(Temp[i] == 1) {

            for(int x : Temp) {
                cout << x;
            }
            cout << endl;
            for(int j=0; j<i; j++) {
                cout << " ";
            }
            for(int x : Divisor) {
                cout << x;
            }
            cout << endl;

            for(int j=0; j<i; j++) {
                cout << " ";
            }
            cout << "-----";
            cout << endl;
            for(int j=0; j<i; j++) {
                cout << " ";
            }

            for(int j = 0; j < n; j++) {
                Temp[i + j] = Temp[i + j] ^ Divisor[j];
                cout << Temp[i + j];
            }

            cout << endl << endl;
        }

        i++;
    }

    //delete i;

    bool flag = false;
    vector<int> remainder;

    for(int i=0; i<Temp.size(); i++) {
        if(!flag && Temp[i] == 1) {flag = true; cout << "\nRemainder: ";}
        if(flag) {
            remainder.push_back(Temp[i]);
            cout << Temp[i];
        }
    }

    
    int m = DATA.size();
    for(int i=0, N = remainder.size(); i<N; i++) {
        DATA[--m] = remainder[N-1-i];
    }
    cout << endl << "DataCodeWord: ";

    for(int x: DATA) {
        cout << x;
    }
    cout << endl;
    return 0;
}