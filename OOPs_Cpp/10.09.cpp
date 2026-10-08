#include<iostream>
using namespace std;

//Write a C++ program to dynamically allocate memory
// an integer array of size n using new operator 
// Accept n elements from the user and perform the following operations:
// 1. Display the elements of the array
// 2. Find the largest element in the array
// 3. find the smallest element in the array
// 4. Calculate the sum of all elements in the array

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    // Dynamically allocate memory for the array
    int* arr = new int[n]; 

    // Accept n elements from the user
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    //initialize variables for largest, smallest and sum
    int largest = arr[0];
    int smallest = arr[0];
    int sum = 0;

    //process the array to find largest, smallest and sum
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
        
        if (arr[i] > largest) {
            largest = arr[i];
        }
        if (arr[i] < smallest) {
            smallest = arr[i];
        }
        sum += arr[i];
    }
    cout << endl;

    float average = (float)sum / n;
    // Display the largest element
    cout << "Largest element: " << largest << endl;

    // Display the smallest element
    cout << "Smallest element: " << smallest << endl;

    // Display the average of all elements
    cout << "Average of all elements: " << average << endl;

    // Display the sum of all elements
    cout << "Sum of all elements: " << sum << endl;

    // Deallocate the dynamically allocated memory
    delete[] arr;

    return 0;
}