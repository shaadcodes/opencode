#include <iostream>
using namespace std;
#define pi 3.14 // Macro definition for pi

/* 
    This program demonstrates the use of macros in C++
    Calculation of area of a circle using a macro for pi
*/

int main() {
    float r;
    cout << "Enter radius of circle: ";
    cin >> r;
    float area = pi * r * r;
    cout << "Area of circle is: " << area << endl;
    return 0;
}