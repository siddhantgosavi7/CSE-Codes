#include<iostream>
#include<string>
using namespace std;
// Create a class Student having the following data members:
// 1. rollNo (int)
// 2. name (string)
// 3. marks (float)


class Student {
private:
    int rollNo;
    string name;
    float marks;
public:
    // Parameterized constructor
    Student(int roll, string n, float m) {
        rollNo = roll;
        name = n;
        marks = m;
        cout << "Student object created: " << name << endl;
    }

    //copy constructor
    Student(const Student &s) {
        rollNo = s.rollNo;
        name = s.name;
        marks = s.marks;
        cout << "Copy constructor called for: " << name << endl;
    }

    // member function to display student details
    void display() {
        cout << "Roll No: " << rollNo << ", Name: " << name << ", Marks: " << marks << endl;
    }
};

int main() {
    int r;
    string n;
    float m;
    cout << "Enter roll number: ";
    cin >> r;
    cout << "Enter name: ";
    cin >> n;
    cout << "Enter marks: ";
    cin >> m;

    // Create a Student object using parameterized constructor
    Student *s1 = new Student(r, n, m);
    Student *s2 = new Student(*s1); // This will call the copy constructor
    
    cout << "\nDetails of the first object:" << endl;
    s1->display();
    cout << "\nDetails of the second object:" << endl;
    s2->display();

    delete s1; // Deallocate memory for the first object
    delete s2; // Deallocate memory for the second object

    return 0;
}