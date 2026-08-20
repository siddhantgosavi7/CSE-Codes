#include<iostream>
using namespace std;

class Point {
private:
    int x, y;
public:
    //Parameterized constructor
    Point(int a, int b) {
        x = a;
        y = b;
    }

    // Overload + Operator
    Point operator+(Point p) {
        // First create an object
        Point temp(0, 0);
        temp.x = x + p.x;
        temp.y = y + p.y;

        return temp;
    }

    void display() {
        cout << "(" << x << ", " << y << ")" << endl;
    }
};

int main() {
    Point P1(3, 5);
    Point P2(2, 4);

    Point P3 = P1 + P2;

    cout << "Result: ";
    P3.display();

    return 0;
}