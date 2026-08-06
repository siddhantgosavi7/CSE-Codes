#include<iostream>
#include<string>
using namespace std;
  
class Movie{
private:
  string name;
  float rating;
public:
  // Default constructor
  Movie() {
    name = "Unknown";
    rating = 0.00;
  }
  
  // Parameterized constructor - 
    Movie(string Name, float Rating) {
      	name = Name;
      	rating = Rating;
    }

  void display() {
    cout << "Name: " << name << endl;
    cout << "Rating: " << rating << endl;
  }
};



int main() {
  Movie M1;
  M1.display();
  
  Movie M2("Fight Club", 9.8);
  M2.display();
  return 0;  
}
