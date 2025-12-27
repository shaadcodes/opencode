#include <iostream>
using namespace std;

/* 
    This program demonstrates the use of pointers in C++ functions. 
    It shows how to pass pointers to functions and modify the values they point to. 
*/

/*
    swapWithPointers() Function
        Swaps the values of two integers using pointers.

    Return Type - void

    Parameters:
        int* a - Pointer to the first integer.
        int* b - Pointer to the second integer.

    Logic:
        1. Store the value pointed to by 'a' in a temporary variable.
        2. Assign the value pointed to by 'b' to the location pointed to by 'a'.
        3. Assign the value stored in the temporary variable to the location pointed to by 'b'.
*/ 

void swapWithPointers(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

/*
    increment() Function
        Increments the value of an integer by 1 using a pointer.

    Return Type - void

    Parameters:
        int* num - Pointer to the integer to be incremented.

    Logic:
        1. Dereference the pointer 'num' and increment the value it points to by 1.
*/

void increment (int* num) {
        (*num)++;
}

//--------------------------------------------MAIN FUNCTION-------------------------------------

int main(){

    int x = 10;
    int y = 20;

    cout << "Before swap: x = " << x << ", y = " << y << endl;

    // Call the swap function with the addresses of x and y
    swapWithPointers(&x, &y);

    cout << "After swap: x = " << x << ", y = " << y << endl;

    int z = 5;
    cout << "Before increment: z = " << z << endl;

    // Call the increment function with the address of z
    increment(&z);

    cout << "After increment: z = " << z << endl;

    return 0;
}