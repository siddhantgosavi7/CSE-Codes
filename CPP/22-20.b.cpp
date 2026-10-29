#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <numeric> // for std::accumulate

using namespace std;

class Person {
public:
    int id, age;
    string name;
};

int main (){
    vector<Person> p;
    Person x;
    ifstream fin("persons.txt");
    string line;

    while (getline(fin, line)){
        stringstream ss(line);
        string id, age;
        getline(ss, id, ',');
        getline(ss, x.name, ',');
        getline(ss, age, ',');
        x.id = stoi(id);
        x.age = stoi(age);
    }
    fin.close();

    int ch;
    do{
        cout << "\n----- Person Menu -----\n";
        cout << "1. Display the list (youngest to oldest)\n";
        cout << "2. Display the list (oldest to youngest)\n";
        cout << "3. Who can vote ?\n";
        cout << "4. Create a new file - with birth years\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> ch;
    }
    if (ch == 1){
        sort(p.begin(), p.end(), [](Person a, Person b) {
            return a.age < b.age;
        });
        cout << "\nList (youngest to oldest):\n";
        for (const Person& person : p) {
            cout << person.id << " " << person.name << " " << person.age << endl;
        }
    }
    else if (ch == 2){
        sort(p.begin(), p.end(), [](Person a, Person b) {
            return a.age > b.age;
        });
        cout << "\nList (oldest to youngest):\n";
        for (const Person& person : p) {
            cout << person.id << " " << person.name << " " << person.age << endl;
        }
    }
    else if (ch == 3){
        cout << "\nPeople who can vote:\n";
        for (const Person& person : p) {
            if (person.age >= 18) {
                cout << person.id << " " << person.name << " " << person.age << endl;
            }
        }
    }
    else if (ch == 4){
        ofstream fout("birth_years.txt");
        for (const Person& person : p) {
            int birthYear = 2024 - person.age; // Assuming current year is 2024
            fout << person.id << "," << person.name << "," << birthYear << endl;
        }
        fout.close();
        cout << "File 'birth_years.txt' created successfully.\n";
    }
    else if (ch == 5){
        cout << "Exiting program...\n";
}
return 0;