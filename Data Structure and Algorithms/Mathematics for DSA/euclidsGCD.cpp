#include <iostream>
using namespace std;

/*
    gcd() Function

    Return type - Integer

    Arguments
        1. Integer a
        2. Integer b

    Approach
        Apply Euclid's algorithm to find GCD of two numbers
        Iterative Approach:
            While b is not zero
                Store b in a temporary variable
                Update b to a % b
                Update a to the temporary variable
            Return a as GCD
        Recursive Approach:
            Will be updated soon

    Time Complexity: O(log(min(a, b)))
    Space Complexity: O(1) for iterative approach
*/

int gcd(int a, int b)
{
    if (b == 0)
        return a;

    if (a == 0)
        return b;

    while (a != b)
    {

        if (a > b)
            a -= b;
        else
            b -= a;
    }
    return a;
}

// ----------------------------------------------MAIN FUNCTION--------------------------------------

int main()
{
    int a, b;
    cout << "Enter two numbers to find GCD: ";
    cin >> a >> b;
    cout << "GCD of " << a << " and " << b << " is: " << gcd(a, b) << endl;
    return 0;
}