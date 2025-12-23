#include<iostream>
using namespace std;

/*
    Loops in C++

    This program demonstrates the use of different types of loops in C++.
    It prints even numbers, odd numbers, and a sequence of numbers up to a user-defined limit.

        - for loop: Used for iterating a block of code a specific number of times.
        - while loop: Used for iterating a block of code as long as a specified condition is true.
        - do - while loop: Similar to while loop, but guarantees at least one execution of the block.

*/

int main(){

    int number;
    cout << "Enter an integer: ";
    cin >> number;

    // Print all even numbers up to the entered number using a for loop
    cout << "Even numbers up to " << number << " are: ";
    for (int i = 0; i <= number; i += 2) {
        cout << i << " ";
    }
    cout << endl;

    // Print all odd numbers up to the entered number using a while loop
    cout << "Odd numbers up to " << number << " are: ";
    int j = 1;
    while (j <= number) {
        cout << j << " ";
        j += 2;
    }
    cout << endl;

    // Print numbers from 1 to the entered number using a do-while loop
    cout << "Numbers from 1 to " << number << " are: ";
    int k = 1;
    do {
        cout << k << " ";
        k++;
    } while (k <= number);
    cout << endl;

    return 0;
}