#include <iostream>
using namespace std;

class Student {
protected:
    string name;
    int rollNo;

public:
    void getStudentData() {
        cout << "Enter name: ";
        cin >> name;

        cout << "Enter roll number: ";
        cin >> rollNo;
    }
};

class Sports {
protected:
    int sportsMarks;

public:
    void getSportsData() {
        cout << "Enter sports marks: ";
        cin >> sportsMarks;
    }
};

class Result : public Student, public Sports {
    int academicMarks;

public:
    void getResultData() {
        cout << "Enter academic marks: ";
        cin >> academicMarks;
    }

    void displayResult() {
        int total = academicMarks + sportsMarks;

        cout << "\n--- Student Result ---" << endl;
        cout << "Name           : " << name << endl;
        cout << "Roll No        : " << rollNo << endl;
        cout << "Academic Marks : " << academicMarks << endl;
        cout << "Sports Marks   : " << sportsMarks << endl;
        cout << "Total Marks    : " << total << endl;

        if (total >= 40)
            cout << "Result         : Pass" << endl;
        else
            cout << "Result         : Fail" << endl;
    }
};

int main() {
    // Object of Result class
    Result r;

    r.getStudentData();
    r.getSportsData();
    r.getResultData();
    r.displayResult();

    return 0;
}