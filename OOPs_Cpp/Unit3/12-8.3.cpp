#include <iostream>
using namespace std;

//3.Create a base class File with a constructor and destructor that print messages.
//Create a derived class TextFile with a constructor and destructor that also print messages.
//Create one TextFile object and observe the order of execution.

class File {
public:
    File() {
        cout << "File constructor called." << endl;
    }
    ~File() {
        cout << "File destructor called." << endl;
    }
};

class TextFile : public File {
public:
    TextFile() {
        cout << "TextFile constructor called." << endl;
    }
    ~TextFile() {
        cout << "TextFile destructor called." << endl;
    }
};

int main() {
    TextFile tf;
    return 0;
}