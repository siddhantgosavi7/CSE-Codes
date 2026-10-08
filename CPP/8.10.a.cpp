
#include <iostream>
using namespace std;

class Employee {
    string name;
    int id;
    float salary;

public:
    // Default Constructor
    Employee() {
        name = "Unknown";
        id = 0;
        salary = 0;
    }

    // Parameterized Constructor
    Employee(string n, int i, float s) {
        name = n;
        id = i;
        salary = s;
    }

    // Copy Constructor
    Employee(Employee &e) {
        name = e.name;
        id = e.id;
        salary = e.salary;
    }

    // Display function
    void display() {
        cout << "Name   : " << name << endl;
        cout << "ID     : " << id << endl;
        cout << "Salary : " << salary << endl;
        cout << "--------------------" << endl;
    }
};

int main() {
    // Default constructor
    Employee e1;

    cout << "Employee 1 (Default Constructor):" << endl;
    e1.display();

    // Parameterized constructor
    Employee e2("Rahul", 101, 45000);

    cout << "Employee 2 (Parameterized Constructor):" << endl;
    e2.display();

    // Copy constructor
    Employee e3(e2);

    cout << "Employee 3 (Copy Constructor):" << endl;
    e3.display();

    return 0;
}
