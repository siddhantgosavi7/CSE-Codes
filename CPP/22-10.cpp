#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class Student {
public:
    int roll, marks[4], total = 0;
    string name;
};

int main() {
    vector<Student> s;
    Student st;
    ifstream fin("students.txt");

    while (fin >> st.roll >> st.name
               >> st.marks[0] >> st.marks[1]
               >> st.marks[2] >> st.marks[3]) {
        st.total = 0;
        for (int i = 0; i < 4; i++) {
            st.total += st.marks[i];
        }
        s.push_back(st);
    }

    fin.close();

    int ch, sub;

    do {
        cout << "\n-----Student Merit Menu-----\n";
        cout << "1. Subject merit list\n";
        cout << "2. Overall merit list\n";
        cout << "3. Toppers in all subjects\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> ch;

        if (ch == 1) {
            for (int j = 0; j < 4; j++) {
                vector<Student> temp = s;
                sort(temp.begin(), temp.end(),
                     [j](const Student a, const Student b) {
                         return a.marks[j] > b.marks[j];
                     });

                cout << "\nSubject " << j + 1 << " Merit List:\n";
                for (Student x : temp) {
                    cout << x.roll << " " << x.name << " "
                         << x.marks[j] << endl;
                }
            }
        }
        else if (ch == 2) {
            sort(s.begin(), s.end(),
                 [](const Student a, const Student b) {
                     return a.total > b.total;
                 });

            cout << "\nOverall Merit List:\n";
            for (Student x : s) {
                cout << x.roll << " " << x.name << " "
                     << x.total << endl;
            }
        }
        else if (ch == 3) {
            cout << "Enter subject number (1-4): ";
            cin >> sub;

            if (sub < 1 || sub > 4) {
                cout << "Invalid subject number. Please enter a number between 1 and 4.\n";
                continue;
            }

            int top = 0;
            for (int i = 0; i < (int)s.size(); i++) {
                if (s[i].marks[sub - 1] > s[top].marks[sub - 1]) {
                    top = i;
                }
            }

            cout << "Subject " << sub << " Topper: "
                 << s[top].roll << " " << s[top].name << " "
                 << s[top].marks[sub - 1] << endl;
        }
        else if (ch == 4) {
            for (int j = 0; j < 4; j++) {
                int top = 0;
                for (int i = 0; i < (int)s.size(); i++) {
                    if (s[i].marks[j] > s[top].marks[j]) {
                        top = i;
                    }
                }

                cout << "Subject " << j + 1 << " Topper: "
                     << s[top].roll << " " << s[top].name << " "
                     << s[top].marks[j] << endl;
            }
        }

    } while (ch != 5);

    return 0;
}