#include <iostream>
using namespace std;

class Complex {
private:
    int real, imaginary;

public:
    // Parameterized constructor
    Complex(int r, int i) {
        real = r;
        imaginary = i;
    }

    // Overload + operator
    Complex operator+(Complex c) {
        Complex temp(0, 0);                          // create object
        temp.real = real + c.real;                   // store sum of real parts
        temp.imaginary = imaginary + c.imaginary;    // store sum of imag parts
        return temp;                                 // return the object
    }

    // Overload - operator
    Complex operator-(Complex c) {
        Complex temp(0, 0);                          // create object
        temp.real = real - c.real;                   // store difference of real parts
        temp.imaginary = imaginary - c.imaginary;    // store difference of imag parts
        return temp;                                 // return the object
    }

    void display() {
        cout << real << " + " << imaginary << "i" << endl;
    }
};

int main() {
    Complex c1(5, 3);
    Complex c2(2, 1);

    Complex c3 = c1 + c2;    // Addition
    Complex c4 = c1 - c2;    // Subtraction

    cout << "Addition: ";
    c3.display();

    cout << "Subtraction: ";
    c4.display();

    return 0;
}