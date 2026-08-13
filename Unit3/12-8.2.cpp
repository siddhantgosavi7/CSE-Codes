#include <iostream>
#include <string>
using namespace std;
//2. Create a base class Employee containing:
//* name
//* basicSalary
//Create a derived class Salary containing bonus.
//Create a function calculateSalary() that calculates:
//Final Salary = Basic Salary + Bonus
//Display the employee’s name and final salary.

class Employee {
public:
    string name;
    double basicSalary;
};

class Salary : public Employee {
private:
    double bonus;

public:
    void setBonus(double b) {
        bonus = b;
    }

    double calculateSalary() {
        return basicSalary + bonus;
    }
};

int main() {
    Salary emp;
    emp.name = "John wick";
    emp.basicSalary = 50000;
    emp.setBonus(5000);

    double finalSalary = emp.calculateSalary();
    cout << "Employee Name: " << emp.name << endl;
    cout << "Final Salary: " << finalSalary << endl;

    return 0;
}