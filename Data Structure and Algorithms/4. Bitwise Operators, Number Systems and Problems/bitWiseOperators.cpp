#include<iostream>
using namespace std;

/*
    Bitwise Operators and Number Systems

    This program demonstrates the use of bitwise operators in C++.
    It includes functions to perform bitwise AND, OR, XOR, NOT, left shift, and right shift operations.

        - Bitwise Operators:
            &  : Bitwise AND
            |  : Bitwise OR
            ^  : Bitwise XOR
            ~  : Bitwise NOT
            << : Left Shift
            >> : Right Shift

    C++ Language Standard: C++14
*/

int main() {
    int a, b;

    cout << "Enter two integers: ";
    cin >> a >> b;

    cout << "Bitwise AND (a & b): " << (a & b) << endl;
    cout << "Bitwise OR (a | b): " << (a | b) << endl;
    cout << "Bitwise XOR (a ^ b): " << (a ^ b) << endl;
    cout << "Bitwise NOT (~a): " << (~a) << endl;
    cout << "Left Shift (a << 1): " << (a << 1) << endl;
    cout << "Right Shift (a >> 1): " << (a >> 1) << endl;

    return 0;
}