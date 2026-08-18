#include<iostream>
#include<unordered_map>
#include<vector>
#include<string>
using namespace std;

bool isFlag(string s) {
    if(s.size() < 8) return false;

    if(s[0] != '0' || s[7] != '0')
        return false;

    for(int i = 1; i < 7; i++) {
        if(s[i] == '0')
            return false;
    }

    return true;
}

void suffBit(string &Bit, int x) {
    Bit.push_back('0');

    int n = Bit.size();

    for(int i = n - 2; i >= x; i--) {
        Bit[i + 1] = Bit[i];
    }

    Bit[x + 1] = '0';
}

int main() {

    vector<string> Bits;

    // Block index -> positions of stuffed bits
    unordered_map<int, vector<int>> place;

    string Bit;

    // Get input
    cout << "Enter bits: ";
    cin >> Bit;

    int n = Bit.size();
    int N = n;

    // Divide bits into blocks
    bool flag = isFlag(Bit);

    if(flag) {

        int i = 0;
        string str = "";

        while(i < n) {

            if(isFlag(Bit.substr(i, 8))) {

                if(str != "")
                    Bits.push_back(str);

                Bits.push_back(Bit.substr(i, 8));

                str = "";

                i += 8;
            }
            else {
                str += Bit[i];
                i++;
            }
        }

        if(str != "")
            Bits.push_back(str);
    } else {
        Bits.push_back(Bit);
    }

    // Debugging the vector
    for(string x : Bits) {
        cout << "#" << x << " ";
    } 

    vector<bool> isFlagStr(Bits.size(), false);
    int t = 0;
    while(t < Bits.size() && (Bits.size()-t) >= 4) {
        isFlagStr[t] = true;
        isFlagStr[t+1] = false;
        isFlagStr[t+2] = true;
        isFlagStr[t+3] = false;
        t += 4;
    }

    cout << endl;

    int k = Bits.size();

    // Process only DATA blocks
    for(int i = 0; i < k; i++) {
        if(flag && isFlagStr[i]) {
            i++;
            if(i >= k) break;

        }
        cout << "&" << i << " " << isFlagStr[i] << " ";
        int m = Bits[i].size();
        int count = 0;

        for(int j = 0; j < m; j++) {

            if(Bits[i][j] == '1') {
                count++;
            }
            else {
                count = 0;
            }

            if(count == 5) {

                // Insert stuffed 0
                suffBit(Bits[i], j);

                // Store position of inserted 0
                place[i].push_back(j + 1);

                // Move back so inserted bit is not counted
                j--;

                m++;
            }
        }
    }

    cout << "Bit Count: " << N << endl;

    cout << "\nInput: " << Bit << endl;

    cout << "Output: ";

    for(string x : Bits) {
        cout << x << " ";
    }

    cout << endl;

    // Show stuffed bits
    cout << "        ";

    for(int i = 0; i < Bits.size(); i++) {

        if(i % 2 == 0) {
            cout << "        ";
        }
        else {

            for(int j = 0; j < Bits[i].size(); j++) {

                bool stuffed = false;

                for(int pos : place[i]) {

                    if(pos == j) {
                        stuffed = true;
                        break;
                    }
                }

                if(stuffed)
                    cout << "^";
                else
                    cout << " ";
            }
        }

        cout << " ";
    }

    return 0;
}