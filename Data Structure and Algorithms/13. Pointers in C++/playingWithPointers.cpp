#include <iostream>
using namespace std;

/* 
    This program demonstrates the use of pointers in C++. It shows how to declare a pointer, assign it the
    address of a variable, and use the pointer
*/

// --------------------------------------------MAIN FUNCTION-------------------------------------

int main() {
    int var = 42;          // Declare an integer variable
    int* ptr = &var;      // Declare a pointer and assign it the address of the variable

    cout << "Value of var: " << var << endl;               // Output the value of the variable
    cout << "Address of var: " << &var << endl;            // Output the address of the variable
    cout << "Value of ptr (address of var): " << ptr << endl; // Output the value of the pointer (address of var)
    cout << "Value pointed to by ptr: " << *ptr << endl;      // Output the value pointed to by the pointer
    cout << "Address of ptr: " << &ptr << endl;          // Output the address of the pointer itself
    cout << "Size of pointer ptr: " << sizeof(ptr) << " bytes" << endl; // Output the size of the pointer
    cout << "Size of variable var: " << sizeof(var) << " bytes" << endl; // Output the size of the variable

    int anotherVar = 100;
    ptr = &anotherVar;    // Reassign pointer to another variable

    cout << "Value pointed to by ptr after reassignment: " << *ptr << endl; // Output the value pointed to by the pointer after reassignment

    double doubleVar = 3.14;
    double* doublePtr = &doubleVar; // Declare a pointer to a double variable

    cout << "Value of doubleVar: " << doubleVar << endl;               // Output the value of the double variable
    cout << "Value pointed to by doublePtr: " << *doublePtr << endl;      // Output the value pointed to by the double pointer
    cout << "Size of pointer doublePtr: " << sizeof(doublePtr) << " bytes" << endl; // Output the size of the double pointer
    cout << "Size of variable doubleVar: " << sizeof(doubleVar) << " bytes" << endl; // Output the size of the double variable
    
    return 0;
}