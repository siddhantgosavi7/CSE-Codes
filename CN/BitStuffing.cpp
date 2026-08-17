#include<iostream>
#include<unordered_map>
#include<vector>
#include<string>
using namespace std;

bool isFlag(string s) {
    if(s.size() < 8) return false;
    //cout << s << endl;
    if(s[0] != '0' || s[7] != '0') return false;

    for(int i=1; i<7; i++) {
        if(s[i] == '0') return false;
    }

    return true;
}

void suffBit(string &Bit, int x) {
    Bit.push_back('0');
    int n = Bit.size();
    
    for(int i=n-2; i>=x; i--) {
        //cout << Bit[i] << " ";
        Bit[i+1] = Bit[i];    
    }

    Bit[x+1] = '0';
    //cout << "test: " << Bit << endl;
}

int main() {
    vector<string> Bits;
    unordered_map<string, vector<int>> place;
    string Bit;

    // get input
    cout << "Enter bits: ";
    cin >> Bit;   
    
    int n = Bit.size(), count = 0;
    int N = n;
    bool flag = isFlag(Bit);

    // Divide bits in block and add in vector
    if(flag) {
        int i = 0;
        string str = "";

        while(i < n) {
            if(isFlag(Bit.substr(i, 8))) {
                if(str != "") Bits.push_back(str);
                Bits.push_back(Bit.substr(i, 8));
                str = "";
                i += 7;
            } else {
                str += Bit[i];
            }
            i++;
        }
        if(str != "") Bits.push_back(str);
    }

    // Debugging the vector
    for(string x : Bits) {
        cout << "#" << x << " ";
    }
    cout << endl;

    int k = Bits.size(); 
    // Loop on string array
    for(int j=1; j<k; j+=2) {
        int m = Bits[j].size();
        count = 0;
        for(int i=0; i<m; i++) {
            
            if(Bits[j][i] == '1') {
                count++;
            } else {
                count = 0;
            }

            //if(isFlag(Bits[j].substr(i, 8))) cout << "flag: " << i << endl;


            if(count == 5) {
                suffBit(Bits[j], i);
                place[Bits[j]].push_back(i+1);
                //cout << "cout: " << i << " ";
                i--;
                m++;
            }
        }
    }

    cout << "Bit Count: ";
    cout << N << endl;

    cout << "\nInput: " << Bit << endl;

    cout << "Output: ";
    for(string x : Bits) {
        cout << x << " ";
    }
    cout << endl;

    cout << "        ";
    for(int i = 0; i < Bits.size(); i++) {

    if(i % 2 == 0) {
        cout << "        ";
    } 
    else {
        for(int j = 0; j < Bits[i].size(); j++) {

            bool stuffed = false;

            for(int pos : place[Bits[i]]) {
                if(pos == j) {
                    stuffed = true;
                    break;
                }
            }

            if(stuffed) {
                cout << "^";
            } else {
                cout << " ";
            }
        }
    }

    cout << " ";
}

    return 0;
}
