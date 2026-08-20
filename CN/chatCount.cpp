#include<iostream>
#include<vector>
#include<string>
using namespace std;


int main() {

    vector<string> Bits;

    string Bit;
    cout << "Enter bits: ";
    cin >> Bit;

    int n = Bit.size();
    cout << "char Count: " << n +1;
    
    return 0;
}