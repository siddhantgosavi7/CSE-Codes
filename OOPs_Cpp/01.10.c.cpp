#include<iostream>
using namespace std;

class Distance {
int meter;
public:
    Distance(int m) {
        meter = m;
    }

    operator int() {
        return meter;
    }

    void display() {
        cout << "Distance = " << meter << " meters\n";
    }
};

int main() {
    int n;
    float f;

    // 1. Int to Float
    cout << "Enter an integer value: ";
    cin >> n;

    float f1 = n;

    cout << "\nInteger to float conversion:\n";
    cout << "Integer value = " << n << endl;
    cout << "Float value = " << f1 << endl;


    // 2, Float to Int
    cout << "\nEnter a floating point value: ";
    cin >> f;
    int n1 = f;
    cout << "\nFloat to Integer conversion:\n";
    cout << "Float value: " << f << endl;
    cout << "Integer value: " << n1 << endl;

    return 0;
}  