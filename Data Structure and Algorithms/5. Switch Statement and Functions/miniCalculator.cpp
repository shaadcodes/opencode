#include <iostream>
using namespace std;

/*
    miniCalculator Program

    Approach:
        Prompt the user to enter two numbers and an operator
        Use a switch statement to perform the operation based on the operator
        Print the result of the operation
        Handle division by zero and invalid operators
*/

// ----------------------------------------------MAIN FUNCTION--------------------------------------

int main()
{
    double num1, num2, result;
    char op;

    cout << "Enter first number: ";
    cin >> num1;
    cout << "Enter an operator (+, -, *, /): ";
    cin >> op;
    cout << "Enter second number: ";
    cin >> num2;

    switch (op)
    {
    case '+':
        result = num1 + num2;
        cout << "Result: " << result << endl;
        break;
    case '-':
        result = num1 - num2;
        cout << "Result: " << result << endl;
        break;
    case '*':
        result = num1 * num2;
        cout << "Result: " << result << endl;
        break;
    case '/':
        if (num2 != 0)
        {
            result = num1 / num2;
            cout << "Result: " << result << endl;
        }
        else
        {
            cout << "Error: Division by zero!" << endl;
        }
        break;
    default:
        cout << "Error: Invalid operator!" << endl;
    }

    return 0;
}