#include <iostream>
using namespace std;

/*
    complement() Function

    Arguments:
        1. Integer n - The number to find the base-10 complement of

    Returns:
        Integer - The base-10 complement of the number

    Approach:
        If n is 0, return 1 (since the complement of 0 is 1)
        Initialize mask to 0 and temp to n
        While temp is not 0
            Right shift temp by 1
            Left shift mask by 1 and set the least significant bit to 1
        Calculate complement by performing bitwise NOT on n and ANDing it with mask
        Return complement
*/

int complement(int n)
{
    if (n == 0)
        return 1;
    int mask = 0, complement = 0, temp = n;
    while (temp != 0)
    {
        temp >>= 1;
        mask <<= 1;
        mask |= 1;
    }
    complement = ~n & mask;
    return complement;
}

// -----------------------------------------MAIN FUNCTION--------------------------------------

int main()
{
    int number;
    cout << "Enter a number: ";
    cin >> number;
    cout << "Base - 10 complement of " << number << " is: " << complement(number) << endl;
}