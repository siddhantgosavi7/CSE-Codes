#include<iostream>
#include<string>
using namespace std;
//Create a base class Student containing name and rollNo.
//Create a derived class Marks containing marks of three subjects.
//Create a function calculateTotal() in the derived class to calculate and display the total marks.

class Student {
public:
    string name;
    int rollNo;
};

class Marks : public Student {
private:
    int subject1;
    int subject2;
    int subject3;
public: 
    void setMarks(int s1, int s2, int s3) {
        subject1 = s1;
        subject2 = s2;
        subject3 = s3;
    }

    void calculateTotal() {
        int total = subject1 + subject2 + subject3;
        cout << "Student Name: " << name << endl;
        cout << "Roll Number: " << rollNo << endl;
        cout << "Total Marks: " << total << endl;
    }
};

int main() {
    Marks student;
    student.name = "Siddhant";
    student.rollNo = 20;
    student.setMarks(85, 90, 78);
    student.calculateTotal();

    return 0;
}