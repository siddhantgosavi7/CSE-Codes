#include<iostream>
#include<string>
using namespace std;
  
class Product{
private:
  int ProductID;
  string ProductName;
  float price;
public:
  // Default constructor
  Product() {
    ProductID = 6082026;
    ProductName = "Unknown";
    price = 0.00;
  }

  void display() {
    cout << "Product ID: " << ProductID << endl;
    cout << "Product Name: " << ProductName << endl;
    cout << "Product Price: " << price << endl;
  }
};



int main() {
  Product P1;
  P1.display();
  
  return 0;  
}
