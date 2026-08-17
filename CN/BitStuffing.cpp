#include<iostream>
#include<string>
using namespace std;


void suffBit(string &Bit, int x) {
    Bit.push_back('0');
    int n = Bit.size();
    
    for(int i=n-2; i>x; i--) {
        Bit[i+1] = Bit[i];    
    }

    Bit[x+1] = '0';
    //cout << "test: " << Bit << endl;
}

int main() {
    string Bit;
    cout << "Enter bits: ";
    cin >> Bit;   
    
    int n = Bit.size(), count;
    int N = n;
    bool Lflag = false, Rflag = false;

    if(n>7 && Bit[0] == '0' && Bit[5] == '0') {
        flag = true;
    }

    for(int i=0; i<n; i++) {
        
        if(Bit[i] == '1') {
            count++;
        } else {
            count = 0;
        }

        if(flag && i<8 && count == 6) {
            continue;
            cout << "Flag incounter in bits!" << endl;
        }

        if(count == 5) {
            suffBit(Bit, i);
            n++;
        }

         
    }

    cout << "Bit Count: " << endl;
    cout << N << endl;

    cout << "Output: " << Bit << endl;

    return 0;
}