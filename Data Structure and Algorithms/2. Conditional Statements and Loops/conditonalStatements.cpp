#include<iostream>
using namespace std;

/*
    Conditional Statements and Loops

    This program demonstrates the use of conditional statements in C++.
    It checks whether a number entered by the user is even or odd

        - Conditional statements allow the program to make decisions based on certain conditions.
            if statement: Executes a block of code if a specified condition is true.
            if - else statement: Executes an alternative block of code if the 'if' condition is false.
            if - else if - else ladder: Allows multiple conditions to be checked in sequence.

        - Loops enable repetitive execution of a block of code until a specified condition is met.
            for loop: Repeats a block of code a specific number of times.
            while loop: Repeats a block of code as long as a specified condition is true.
            do - while loop: Similar to while loop, but guarantees at least one execution of the block.

*/

int main() {
    int number;

    // Prompt user for a number
    cout << "Enter an integer: ";
    cin >> number;

    // if statement to check if the number is positive
    if (number >= 0) {
        cout << number << " is a positive number." << endl;
    }

    // Check if the number is even or odd using if-else statement
    if (number % 2 == 0) {
        cout << number << " is an even number." << endl;
    } else {
        cout << number << " is an odd number." << endl;
    }

    // if - else if - else ladder to categorize the number
    if (number > 0) {
        cout << number << " is positive." << endl;
    } else if (number < 0) {
        cout << number << " is negative." << endl;
    } else {
        cout << "The number is zero." << endl;
    }

    return 0;
}