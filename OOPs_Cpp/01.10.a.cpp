#include<iostream>
using namespace std;

class Area {
public:

    float calculateArea(int length, int width) {
        cout << "Area of rectangle: " << length * width << endl;
        return length * width;
    }

    float calculateArea(float radius) {
        cout << "Area of circle: " << 3.14 * radius * radius << endl;
        return 3.14 * radius * radius;
    }

    float calculateArea(int side) {
        cout << "Area of square: " << side * side << endl;
        return side * side;
    }
};

int main() {
    Area area;
    float radius, length, width;
    int side;

    cout << "Enter radius: ";
    cin >> radius;
    area.calculateArea(radius);   // Circle

    cout << "\nEnter length of rectangle: ";
    cin >> length;
    cout << "Enter width of rectangle: ";
    cin >> width;
    area.calculateArea(length, width);
    
    cout << "\nEnter side length of square: ";
    cin >> side;
    area.calculateArea(side);      // Square

    return 0;
}  