#include<iostream>
using namespace std;
  
class BOX{
private:
  int length;
  int breath;
  int height;
public:
  // Parameterized constructor - 
    BOX(int l, int b, int h) {
      	length = l;
      	breath = b;
      	height = h;
    }

  void displayVolume() {
    cout << "Volume: " << length*breath*height << endl;
  }
};



int main() {
  BOX B1(10, 20, 30);
  BOX B2(4, 5, 6);
  // Copy constructor called
  BOX B3(B1);
  
  B1.displayVolume();
  B2.displayVolume();
  B3.displayVolume();
  return 0;  
}
