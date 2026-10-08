#include<iostream>
using namespace std;
// Dynamiclly allocate an integer array of size n using
// the 'new' operator, accept n elemnts
// Display all elements
// Find the largest element
// Find the smallest element
// Calculate the sum and average of the element

int main() {
    int n;

    cout << "Enter the size of array: ";
    cin >> n;
    
    // Dynamiclly allocated array
    int *arr = new int[n];

    //input elements
    cout << "Enter " << n << " elements" << endl;
    for(int i=0; i<n; i++) {
        cout << i + 1 << ") >> ";
        cin >> arr[i];
    }

    int largest = arr[0];
    int smallest = arr[0];
    int sum = 0;

    for(int i=0; i<n; i++) {
        cout << arr[i] << " ";

        if(largest < arr[i]) largest = arr[i];
        if(smallest > arr[i]) smallest = arr[i];

        sum += arr[i];
    }

    cout << "\nLargest: " << largest << endl;
    cout << "Smallest: " << smallest << endl;
    cout << "Sum: " << sum << endl;
    cout << "Avg: " << (float)sum/n << endl;
    delete[] arr;

    return 0;
}