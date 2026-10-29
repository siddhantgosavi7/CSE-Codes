#include <iostream>
using namespace std;

template <typename T>
class Storage {
    T arr[5];

public:
    void input() {
        cout << "Enter 5 elements: ";
        for (int i = 0; i < 5; i++)
            cin >> arr[i];
    }

    void display() {
        cout << "Elements: ";
        for (int i = 0; i < 5; i++)
            cout << arr[i] << " ";
        cout << endl;
    }

    void search(T key) {
        for (int i = 0; i < 5; i++) {
            if (arr[i] == key) {
                cout << "Element found at position " << i + 1 << endl;
                return;
            }
        }
        cout << "Element not found!" << endl;
    }

    void largest() {
        T max = arr[0];
        for (int i = 1; i < 5; i++) {
            if (arr[i] > max)
                max = arr[i];
        }
        cout << "Largest element = " << max << endl;
    }
};

int main() {
    // Integer storage
    Storage<int> s1;
    cout << "INTEGER STORAGE\n";
    s1.input();
    s1.display();
    cout << "Enter element to search: ";
    int key1;
    cin >> key1;
    s1.search(key1);
    s1.largest();

    // Floating-point storage
    Storage<double> s2;
    cout << "\nFLOATING-POINT STORAGE\n";
    s2.input();
    s2.display();
    cout << "Enter element to search: ";
    double key2;
    cin >> key2;
    s2.search(key2);
    s2.largest();

    return 0;
}