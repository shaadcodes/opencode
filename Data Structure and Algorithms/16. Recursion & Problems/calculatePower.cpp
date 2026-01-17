#include <iostream>
using namespace std;

/*
    raiseTo() Function

    Return type - int

    Arguments
        1. Integer base
        2. Integer power

    Approach
        Base case 1: If base is not 0 and power is 0, return 1 (any number raised to power 0 is 1)
        Base case 2: If base is 0, return 0 (0 raised to any power is 0)
        Base case 3: If power is 1, return base (any number raised to power 1 is the number itself)
        Recursive case: Multiply base with the result of raiseTo(base, power - 1)
        
    Time Complexity: O(n) where n is the power
    Space Complexity: O(n) due to recursive call stack
*/

int raiseTo(int base, int power)
{
    if (base != 0 && power == 0)
        return 1;

    if (base == 0)
        return 0;

    if (power == 1)
        return base;

    int result = base * raiseTo(base, --power);

    return result;
}

// -----------------------------------------------MAIN FUNCTION-------------------------------------------------

int main()
{
    int base, power;

    cout << "Enter base: ";
    cin >> base;
    cout << "Enter Power: ";
    cin >> power;

    cout << raiseTo(base, power) << endl;
}