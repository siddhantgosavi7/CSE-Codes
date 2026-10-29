#include <iostream>
using namespace std;

template <typename T>
T add(T a, T b) { return a + b; }

template <typename T>
T diff(T a, T b) { return a - b; }

template <typename T>
T product(T a, T b) { return a * b; }

template <typename T>
T maximum(T a, T b) { return (a > b) ? a : b; }

template <typename T>
T minimum(T a, T b) { return (a < b) ? a : b; }

int main() {
    int a = 10, b = 4;
    double x = 7.5, y = 2.5;

    cout << "--- Integer ---" << endl;
    cout << "Sum     : " << add(a, b) << endl;
    cout << "Diff    : " << diff(a, b) << endl;
    cout << "Product : " << product(a, b) << endl;
    cout << "Max     : " << maximum(a, b) << endl;
    cout << "Min     : " << minimum(a, b) << endl;

    cout << "--- Floating point ---" << endl;
    cout << "Sum     : " << add(x, y) << endl;
    cout << "Diff    : " << diff(x, y) << endl;
    cout << "Product : " << product(x, y) << endl;
    cout << "Max     : " << maximum(x, y) << endl;
    cout << "Min     : " << minimum(x, y) << endl;

    return 0;
}