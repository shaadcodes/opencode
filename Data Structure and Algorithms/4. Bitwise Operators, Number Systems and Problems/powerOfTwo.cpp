#include <iostream>
using namespace std;

/*

    ifPowerOfTwo() Function

    Arguments:
        1. Integer number - The number to check if it is a power of 2

    Returns:
        Boolean - true if the number is a power of 2, false otherwise

    Approach:
        Loop through integers i from 0 to 30
            If number is equal to 2 raised to the power i
                Return true
        If no match is found, return false

    Constraints:

        -2^31 <= n <= (2^31) - 1

*/

bool ifPowerOfTwo(int number)
{
    for (int i = 0; i < 31; i++)
    {
        if (number == pow(2, i))
            return true;
    }
    return false;
}

/*

    isPowerOfTwo() Function

    Arguments:
        1. Integer number - The number to check if it is a power of 2

    Returns:
        Boolean - true if the number is a power of 2, false otherwise

    Approach:
        A number is a power of 2 if it is greater than 0 and the bitwise AND of the number and (number - 1) is 0

*/

bool isPowerOfTwo(int number) {
        if (number > 0 && (number&(number-1)) == 0) return true;
        return false;
    }

// -----------------------------------------MAIN FUNCTION--------------------------------------

int main()
{
    int number;
    cout << "Enter the number: ";
    cin >> number;
    if (ifPowerOfTwo(number))
    {
        cout << number << " is a power of 2" << endl;
    }
    else
    {
        cout << number << " is not a power of 2" << endl;
    }
    // cout << isPowerOfTwo(number) << endl;
    return 0;
}