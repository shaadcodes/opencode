#include <iostream>
using namespace std;

/*
    fib() Function
        This function takes an integer n as input and returns the nth Fibonacci number using recursion.

    Arguments:
        n : An integer representing the position in the Fibonacci sequence.

    Returns:
        An integer representing the nth Fibonacci number.

    Approach:
        The function uses the base cases of the Fibonacci sequence:
            - fib(0) = 0
            - fib(1) = 1
        For n > 1, it recursively calls itself to compute the sum of the two preceding Fibonacci numbers:
            - fib(n) = fib(n-1) + fib(n-2)
*/

int fibRecursive(int n)
{
    if (n == 0)
        return 0;

    if (n == 1)
        return 1;

    return fibRecursive(n - 1) + fibRecursive(n - 2);
}

/*
    fibIterative() Function
        This function takes an integer n as input and returns the nth Fibonacci number using an iterative approach.

    Arguments: 
        n : An integer representing the position in the Fibonacci sequence.

    Returns:
        An integer representing the nth Fibonacci number.

    Approach:
        The function initializes the first two Fibonacci numbers and iteratively computes the subsequent numbers up to n:
            - It uses a loop starting from 2 up to n, updating the first and second Fibonacci numbers in each iteration.
            - The final computed Fibonacci number is returned.
*/

int fibIterative(int n) {

    if (n == 0)
    return 0;

    if (n == 1)
    return 1;

    int first = 0, second = 1, final;
    for (int i = 2; i <= n; i++){
        final = first + second;
        first = second;
        second = final;
    }

    return final;
}


// -------------------------------------------------MAIN FUNCTION-------------------------------------------------

int main() {
    int n, choice;

    cout << "What do you want to do?" << endl;
    cout << "\t1. Find nth fibonacci number using recursive approach" << endl;
    cout << "\t2. Find nth fibonacci number using iterative approach" << endl;
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice) {
        case 1:
            cout << "Enter the value of n: ";
            cin >> n;
            cout << n << "th fibonacci number (using recursive approach) is: " << fibRecursive(n) << endl;
            break;
        case 2:
            cout << "Enter the value of n: ";
            cin >> n;
            cout << n << "th fibonacci number (using iterative approach) is: " << fibIterative(n) << endl;
            break;
        default:
            cout << "Invalid choice!" << endl;
    }

    return 0;
}