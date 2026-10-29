#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <functional>
using namespace std;

void displayMarks(const vector<int>& v) {
    if (v.empty()) {
        cout << "No marks available." << endl;
        return;
    }
    cout << "Marks: ";
    for (size_t i = 0; i < v.size(); i++)
        cout << v[i] << " ";
    cout << endl;
}

int main() {
    vector<int> marks;
    int n, m;

    cout << "Enter number of students: ";
    cin >> n;
    cout << "Enter marks of " << n << " students: ";
    for (int i = 0; i < n; i++) {
        cin >> m;
        marks.push_back(m);
    }

    int choice;
    do {
        cout << "\n----- MENU -----" << endl;
        cout << "0. Display all marks" << endl;
        cout << "1. Insert a new mark" << endl;
        cout << "2. Delete a specific mark" << endl;
        cout << "3. Sort marks (ascending & descending)" << endl;
        cout << "4. Search a mark" << endl;
        cout << "5. Display highest and lowest marks" << endl;
        cout << "6. Calculate average marks" << endl;
        cout << "7. Display unique marks (using set)" << endl;
        cout << "8. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 0:
            displayMarks(marks);
            break;

        case 1:
            cout << "Enter mark to insert: ";
            cin >> m;
            marks.push_back(m);
            cout << "Mark inserted." << endl;
            break;

        case 2: {
            cout << "Enter mark to delete: ";
            cin >> m;
            vector<int>::iterator it = find(marks.begin(), marks.end(), m);
            if (it != marks.end()) {
                marks.erase(it);
                cout << "Mark deleted." << endl;
            } else {
                cout << "Mark not found." << endl;
            }
            break;
        }

        case 3:
            sort(marks.begin(), marks.end());
            cout << "Ascending : ";
            displayMarks(marks);
            sort(marks.begin(), marks.end(), greater<int>());
            cout << "Descending: ";
            displayMarks(marks);
            break;

        case 4: {
            cout << "Enter mark to search: ";
            cin >> m;
            vector<int>::iterator it = find(marks.begin(), marks.end(), m);
            if (it != marks.end())
                cout << "Found at position " << (it - marks.begin()) << endl;
            else
                cout << "Mark not found." << endl;
            break;
        }

        case 5:
            if (marks.empty()) {
                cout << "No marks available." << endl;
            } else {
                cout << "Highest: " << *max_element(marks.begin(), marks.end()) << endl;
                cout << "Lowest : " << *min_element(marks.begin(), marks.end()) << endl;
            }
            break;

        case 6:
            if (marks.empty()) {
                cout << "No marks available." << endl;
            } else {
                double sum = 0;
                for (size_t i = 0; i < marks.size(); i++)
                    sum += marks[i];
                cout << "Average: " << sum / marks.size() << endl;
            }
            break;

        case 7: {
            set<int> unique(marks.begin(), marks.end());
            cout << "Unique marks: ";
            for (set<int>::iterator it = unique.begin(); it != unique.end(); ++it)
                cout << *it << " ";
            cout << endl;
            break;
        }

        case 8:
            cout << "Exiting..." << endl;
            break;

        default:
            cout << "Invalid choice." << endl;
        }
    } while (choice != 8);

    return 0;
}