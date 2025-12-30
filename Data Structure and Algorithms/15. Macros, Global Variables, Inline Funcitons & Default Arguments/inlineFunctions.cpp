#include <iostream>
using namespace std;

/* 
    This program demonstrates the use of inline functions in C++
    It defines an inline function to calculate the square of a number
*/

// Inline function to calculate square of a number

inline int square(int x) {
    return x * x;
}

// ---------------------------------------------------MAIN FUNCTION---------------------------------------------------

int main() {
    int num;
    cout << "Enter a number to find its square: ";
    cin >> num;
    int result = square(num);
    cout << "Square of " << num << " is: " << result << endl;
    return 0;
}