#include <iostream>
using namespace std;

/* 
    This program demonstrates the use of default arguments in C++
    It defines a function to calculate the volume of a cuboid with default height
*/

/*
    Function to calculate volume of a cuboid
    Default height is set to 1.0

    Arguments:
        length - length of the cuboid
        width  - width of the cuboid
        height - height of the cuboid (default is 1.0)

    Returns:
        Volume of the cuboid
    
    Approach:
        Volume is calculated using the formula: length * width * height
*/

double volume(double length, double width, double height = 1.0) {
    return length * width * height;
}

// ---------------------------------------------------MAIN FUNCTION---------------------------------------------------

int main() {
    double length, width, height;
    cout << "Enter length and width of the cuboid: ";
    cin >> length >> width;

    // Using default height
    double vol1 = volume(length, width);
    cout << "Volume of cuboid with default height (1.0) is: " << vol1 << endl;

    // Using user-defined height
    cout << "Enter height of the cuboid: ";
    cin >> height;
    double vol2 = volume(length, width, height);
    cout << "Volume of cuboid with height " << height << " is: " << vol2 << endl;

    return 0;
}