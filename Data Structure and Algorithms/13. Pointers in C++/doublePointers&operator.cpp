#include <iostream>
using namespace std;

/* 
    This program demonstrates the use of double pointers, reference variables and the dereference operator in C++. 
    It shows how to use double pointers to modify the value of a variable indirectly.
*/

/*
    modifyValue() Function
        Modifies the value of an integer using a double pointer.

    Return Type - void

    Parameters:
        int** ptr - Double pointer to the integer to be modified.

    Logic:
        1. Dereference the double pointer 'ptr' to get the single pointer.
        2. Dereference the single pointer to modify the value it points to.
*/

void modifyValue(int** ptr) {
    **ptr = 99; // Modify the value pointed to by the single pointer
}

//--------------------------------------------MAIN FUNCTION-------------------------------------

int main() {
    int value = 10;               // Declare an integer variable
    int* singlePtr = &value;     // Declare a single pointer and assign it the address of the variable
    int** doublePtr = &singlePtr; // Declare a double pointer and assign it the address of the single pointer

    cout << "Original value: " << value << endl; // Output the original value

    // Call the function to modify the value using the double pointer
    modifyValue(doublePtr);

    cout << "Modified value: " << value << endl; // Output the modified value

    // Demonstrating reference variable
    int& refVar = value; // Declare a reference variable to 'value'
    refVar = 50;         // Modify the value using the reference variable

    cout << "Value after modifying through reference variable: " << value << endl; // Output the modified value

    return 0;
}