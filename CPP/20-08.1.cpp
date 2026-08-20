#include<iostream>
using namespace std;
//create a parameterized contructor
//Overload the '+' operator to add two complex numbers.
//Overload the '-' operator two complex numbers
//Display both results

class Complex {
private:
    int real, imginary;
public:
    //Parameterized constructor
    Complex(int r, int i) {
        real = r;
        imginary = i;
    }

    // Overload + Operator
    Complex operator+(Complex c) {
        // First create an object
        Complex temp(0, 0);
        temp.real = real + c.real;
        temp.imginary = imginary + c.imginary;

        return temp;
    }

    // Overload - Operator
    Complex operator-(Complex c) {
        // First create an object
        Complex temp(0, 0);
        temp.real = real - c.real;
        temp.imginary = imginary - c.imginary;

        return temp;
    }

    void display() {
        cout << real << "+ " << imginary << "i" << endl;
    }
};

int main() {
    Complex C1(3, 5);
    Complex C2(2, 4);
    C1.display();
    C2.display();

    Complex C3 = C1 + C2;
    Complex C4 = C1 - C2;

    cout << "\nAddition: ";
    C3.display();
    cout << "Sub: ";
    C4.display();

    return 0;
}