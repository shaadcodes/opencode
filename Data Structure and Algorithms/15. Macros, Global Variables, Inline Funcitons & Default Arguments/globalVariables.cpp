#include <iostream>
using namespace std;

// Global variable declaration
int globalCounter = 0;

/* 
    This program demonstrates the use of global variables in C++
    It increments a global counter each time a function is called
*/

// Function to increment the global counter
void incrementCounter() {
    globalCounter++;
}

// ---------------------------------------------------MAIN FUNCTION---------------------------------------------------
int main() {
    int n;
    cout << "Enter number of times to increment the counter: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        incrementCounter();
    }
    cout << "Global counter value after incrementing " << n << " times is: " << globalCounter << endl;
    return 0;
}