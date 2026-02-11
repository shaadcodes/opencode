#include <iostream>
using namespace std;

/*
    fact() Function
        This function takes an integer n as input and returns the factorial of n using recursion.

    Arguments:
        n : An integer for which the factorial is to be calculated.

    Returns:
        An integer representing the factorial of n.

    Approach:
        The function uses the base cases of the factorial function:
            - fact(0) = 1
            - fact(1) = 1
        For n > 1, it recursively calls itself to compute the product of n and the factorial of (n-1):
            - fact(n) = n * fact(n-1)
    
    Time Complexity: O(n) due to the linear number of recursive calls.
    Space Complexity: O(n) due to the recursive call stack.
*/

int fact(int n)
{
    if (n == 0 || n == 1)
        return 1;

    return n * fact(n - 1);
}

// --------------------------------------------------MAIN FUNCTION--------------------------------------------------

int main()
{
    int n;
    cout << "Enter a number: ";
    cin >> n;

    int factorial = fact(n);

    cout << "Factorial of " << n << " is: " << factorial << endl;

    return 0;
}