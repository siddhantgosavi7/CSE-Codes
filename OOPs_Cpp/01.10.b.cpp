#include<iostream>
using namespace std;

class Shape {
public:
    virtual void area() {
        cout << "Area of shape: ";
    }

    virtual ~Shape() {} // virtual destructor
};

class Circle : public Shape {
    float radius;
public: 
    Circle(float r) {
        radius = r;
    }
    void area() override {
        cout << "Area of circle  = " << 3.14 * radius * radius << endl;
    }
};

class Rectangle : public Shape {
    float length, width;
public:
Rectangle(float l, float w) {
    length = l;
    width = w;
}

    void area() override {
        cout << "Area of rectangle = " << length * width << endl;
    }
};


int main() {
    float radius, length, width;

    cout << "Enter radius: ";
    cin >> radius;

    cout << "\nEnter length of rectangle: ";
    cin >> length;
    cout << "Enter width of rectangle: ";
    cin >> width;
    
    Circle c(radius);
    Rectangle rect(length, width);
    Shape *ptr; //Base class pointer

    cout << "\nUsing base class pointer: \n";

    ptr = &c; // Pointing to Circle object
    ptr->area(); // Calls Circle's area() at runtime

    ptr = &rect; // Pointing to Rectangle object
    ptr->area(); // Calls Rectangle's area() at runtime

    return 0;
}  