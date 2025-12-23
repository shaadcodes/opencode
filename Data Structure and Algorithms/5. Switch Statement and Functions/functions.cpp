#include <iostream>
using namespace std;

/* Functions Program

    Approach:
        Define multiple functions to perform specific tasks
        Call these functions from the main function to demonstrate their functionality
*/

/*
    addIntegers() Function

    Return type - int

    Arguments
        1. int a - First integer
        2. int b - Second integer

    Approach
        Simply return the sum of the two integers

*/

int addIntegers(int a, int b)
{
    return a + b;
}

/*
    multiplyIntegers() Function

    Return type - int

    Arguments
        1. int a - First integer
        2. int b - Second integer

    Approach
        Simply return the product of the two integers

*/

int multiplyIntegers(int a, int b)
{
    return a * b;
}

/*
    isEven() Function

    Return type - bool

    Arguments
        1. int number - The integer to be checked

    Approach
        Check if the number is divisible by 2
        If yes, return true (even)
        Otherwise, return false (odd)

*/

bool isEven(int number)
{
    return (number % 2 == 0);
}

/*
    nCr() Function

    Return type - int

    Arguments
        1. int n - Total number of items
        2. int r - Number of items to choose

    Approach
        Base Cases:
            If r > n, return 0
            If r == 0 or r == n, return 1
        Recursive Case:
            nCr(n, r) = nCr(n-1, r-1) + nCr(n-1, r)

*/

int nCr(int n, int r)
{
    if (r > n)
        return 0;
    if (r == 0 || r == n)
        return 1;
    return nCr(n - 1, r - 1) + nCr(n - 1, r);
}

/*
    printFactorial() Function

    Return type - int

    Arguments
        1. int n - The integer to find the factorial of

    Approach
        Base Case:
            If n is 0 or 1, return 1
        Recursive Case:
            factorial(n) = n * factorial(n-1)

*/

int printFactorial(int n)
{
    if (n == 0 || n == 1)
        return 1;
    return n * printFactorial(n - 1);
}

// ----------------------------------------------MAIN FUNCTION--------------------------------------

int main()
{
    int num1, num2;

    cout << "Enter first integer: ";
    cin >> num1;
    cout << "Enter second integer: ";
    cin >> num2;

    cout << "Sum: " << addIntegers(num1, num2) << endl;
    cout << "Product: " << multiplyIntegers(num1, num2) << endl;

    if (isEven(num1))
        cout << num1 << " is even." << endl;
    else
        cout << num1 << " is odd." << endl;

    if (isEven(num2))
        cout << num2 << " is even." << endl;
    else
        cout << num2 << " is odd." << endl;

    int n, r;
    cout << "Enter n and r for nCr calculation: ";
    cin >> n >> r;
    cout << "nCr(" << n << ", " << r << ") = " << nCr(n, r) << endl;
    cout << "Factorial of " << n << " is: " << printFactorial(n) << endl;

    return 0;
}