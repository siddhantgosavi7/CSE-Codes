#include<iostream>
using namespace std;

class Distance {
private:
    int feet, inch;
public:
    //Parameterized constructor
    Distance(int f, int i) {
        feet = f;
        inch = i;
    }

    // Overload * Operator
    Distance operator*(int n) {
        // First create an object
        Distance temp(0, 0);
        int totalInch = (feet * 12 + inch) * n;
        temp.feet = totalInch/12;
        temp.inch = totalInch%12;

        return temp;
    }

    // friend function for 3 * d1
    friend Distance operator*(int n, Distance d);

    void display() {
        cout << feet << "feet " << inch << "inchs" << endl;
    }
};

 Distance operator*(int n, Distance d) {
        // First create an object
        Distance temp(0, 0);
        int totalInch = (d.feet * 12 + d.inch) * n;
        temp.feet = totalInch/12;
        temp.inch = totalInch%12;

        return temp;
    }

int main() {
    Distance D1(5, 6);
    Distance D2(5, 5);
    cout << "D1: ";
    D1.display();
    cout << "D2: ";
    D2.display();

    Distance D3 = D1 * 2;
    Distance D4 = 10 * D2;

    cout << "\nD1 * 20: ";
    D3.display();

    cout << "\nD2 * 10: ";
    D4.display();

    return 0;
}