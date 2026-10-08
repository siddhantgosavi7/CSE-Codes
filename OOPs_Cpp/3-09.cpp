#include<iostream>
using namespace std;
//dyanamic memory allocation of 2 pointers and the 'new' oprator, accept values from the user and perfom
// Adition
//SUb
//Multi
// Divide

int main() {
    int *a = new int;
    int *b = new int;

    cout << "Enter two numbers: ";
    cin >> *a;
    cout << "Enter two numbers: ";
    cin >> *b;


    cout << "Add: " << *a + *b << endl;
    cout << "Sub: " << *a - *b << endl;
    cout << "Multi: " << *a * *b << endl;

    if(*b == 0) {
        cout << "Divsion: Can NOT divide by 0" << endl;
    } else {
        cout << "Divide: " << (float)*a / *b << endl;
    }

    delete a;
    delete b;

    return 0;
}