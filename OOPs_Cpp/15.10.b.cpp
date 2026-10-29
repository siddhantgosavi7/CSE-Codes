#include <iostream>
using namespace std;

template <typename T>
class Storage {
    T arr[5];

public:
    void accept() {
        cout << "Enter 5 elements: ";
        for (int i = 0; i < 5; i++)
            cin >> arr[i];
    }

    void display() const {
        cout << "Elements: ";
        for (int i = 0; i < 5; i++)
            cout << arr[i] << " ";
        cout << endl;
    }

    bool search(T key) const {
        for (int i = 0; i < 5; i++)
            if (arr[i] == key)
                return true;
        return false;
    }

    T largest() const {
        T big = arr[0];
        for (int i = 1; i < 5; i++)
            if (arr[i] > big)
                big = arr[i];
        return big;
    }
};

int main() {
    cout << "=== Integer Storage ===" << endl;
    Storage<int> s1;
    s1.accept();
    s1.display();
    int key1;
    cout << "Enter element to search: ";
    cin >> key1;
    cout << (s1.search(key1) ? "Found" : "Not found") << endl;
    cout << "Largest: " << s1.largest() << endl;

    cout << "\n=== Floating Point Storage ===" << endl;
    Storage<float> s2;
    s2.accept();
    s2.display();
    float key2;
    cout << "Enter element to search: ";
    cin >> key2;
    cout << (s2.search(key2) ? "Found" : "Not found") << endl;
    cout << "Largest: " << s2.largest() << endl;

    return 0;
}