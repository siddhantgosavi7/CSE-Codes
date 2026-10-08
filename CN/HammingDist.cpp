#include<iostream>
#include<string>
using namespace std;


int main() {
    string Data1, Data2;
    int count = 0;

    cout << "Enter first bits: ";
    cin >> Data1;

    cout << "Enter second bits: ";
    cin >> Data2;

    if(Data1.length() != Data2.length()) {
        cout << "Both bits must be of same length." << endl;
        return 0;
    }

    for(int i = 0; i < Data1.length(); i++) {
        if(Data1[i] != Data2[i]) {
            count++;
        }
    }

    cout << "Hamming Distance: " << count << endl;

    return 0;
}