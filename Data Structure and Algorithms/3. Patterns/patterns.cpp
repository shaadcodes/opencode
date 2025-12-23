#include <iostream>
using namespace std;

/*
    Patterns in C++

    This program demonstrates how to print a simple pattern using nested loops.
    It prints a square pattern of numbers from 1 to n, where n is provided by the user.

        - Nested loops: A loop inside another loop. The outer loop controls the number of rows,
          while the inner loop controls the number of columns.

*/

// Print square pattern of numbers from 1 to n Row Wise

void printNumbersSquareRowWise(void)
{
    int i = 1, j, n;
    cout << "Enter limit\n";
    cin >> n;

    while (i <= n)
    {
        j = 1;
        while (j <= n)
        {
            cout << j << "  ";
            j++;
        }
        cout << "\n";
        i++;
    }
}

// Print square pattern of numbers from n to 1 Column Wise

void printNumbersSquareColumnWise()
{
    int i = 1, j, n;
    cout << "Enter limit\n";
    cin >> n;

    while (i <= n)
    {
        j = n;
        while (j >= 1)
        {
            cout << j << "  ";
            j--;
        }
        cout << "\n";
        i++;
    }
}

// Print numbers from 1 to n*n in a square pattern

void printNumbersTillSquare(void)
{
    int i = 1, j, n;

    cout << "Enter limit\n";
    cin >> n;

    while (i <= (n * n))
    {
        j = 0;
        while (j < n)
        {
            cout << i << "  ";
            i++;
            j++;
        }
        cout << "\n";
    }
}

// Print line pattern of numbers from 1 to n

void printLinePattern(void)
{
    int n, i = 1, j;
    cout << "Enter limit\n";
    cin >> n;

    while (i <= n)
    {
        j = 1;
        while (j <= n)
        {
            cout << i << "  ";
            j++;
        }
        cout << "\n";
        i++;
    }
}

// Print Triangle pattern of numbers

void printTrianglePattern(void)
{
    int i = 1, j, n;

    cout << "Enter limit\n";
    cin >> n;

    while (i <= n)
    {
        j = 1;
        while (j <= i)
        {
            cout << i << "  ";
            j++;
        }
        cout << "\n";
        i++;
    }
}

// Print Triangle pattern of increasing numbers

void printTrianglePatternIncreasingNumbers()
{
    int i = 1, j, n, k = 1;
    cout << "Enter limit\n";
    cin >> n;

    while (i <= n)
    {
        j = 1;
        while (j <= i)
        {
            cout << k << "  ";
            k++;
            j++;
        }
        cout << "\n";
        i++;
    }
}

// Print Triangle pattern of increasing numbers line wise

void printTrianglePatternIncreasingNumbersLineWise()
{
    int i = 1, j, n, k;

    cout << "Enter limit\n";
    cin >> n;

    while (i <= n)
    {
        j = 1;
        k = i;
        while (j <= i)
        {
            cout << k << "  ";
            k++;
            j++;
        }
        cout << "\n";
        i++;
    }
}

// Print Triangle pattern second version

void printTrianglePatternSecondVersion()
{
    int i = 0, j, n, k = 1;

    cout << "Enter limit\n";
    cin >> n;

    while (i < n)
    {
        j = 0;
        while (j <= i)
        {
            cout << (i + j + 1) << "  ";
            j++;
        }
        cout << "\n";
        i++;
    }
}

// Print Triangle pattern in decreasing order of numbers

void printReverseTriangle()
{
    int i = 1, j, n, k = 1;

    cout << "Enter limit\n";
    cin >> n;

    while (i <= n)
    {
        j = 1;
        k = i;
        while (j <= i)
        {
            cout << k << "  ";
            k--;
            j++;
        }
        cout << "\n";
        i++;
    }
}

// Print star square pattern

void starSquarePattern(void)
{
    int i = 0, j, n;

    cout << "Enter the side of a square\n";
    cin >> n;

    while (i < n)
    {
        j = 0;
        while (j < n)
        {
            cout << "*  ";
            j++;
        }
        cout << endl;
        i++;
    }
}

// Print star triangle pattern

void printStarTriangle(void)
{
    int i = 0, j, n;

    cout << "Enter limit\n";
    cin >> n;

    while (i < n)
    {
        j = 0;
        while (j <= i)
        {
            cout << "*  ";
            j++;
        }
        cout << "\n";
        i++;
    }
}

int main()
{
    do {
        cout << "\n\n-------Pattern Menu-------\n\n";
        cout << "1. Numbers Square Row Wise\n";
        cout << "2. Numbers Square Column Wise\n";
        cout << "3. Numbers Till Square\n";
        cout << "4. Line Pattern\n";
        cout << "5. Triangle Pattern\n";
        cout << "6. Triangle Pattern Increasing Numbers\n";
        cout << "7. Triangle Pattern Increasing Numbers Line Wise\n";
        cout << "8. Triangle Pattern Second Version\n";
        cout << "9. Reverse Triangle\n";
        cout << "10. Star Square Pattern\n";
        cout << "11. Star Triangle Pattern\n";
        cout << "12. Exit\n";
        cout << "Enter your choice: ";
        int choice;
        cin >> choice;

        switch (choice) {
            case 1:
                printNumbersSquareRowWise();
                break;
            case 2:
                printNumbersSquareColumnWise();
                break;
            case 3:
                printNumbersTillSquare();
                break;
            case 4:
                printLinePattern();
                break;
            case 5:
                printTrianglePattern();
                break;
            case 6:
                printTrianglePatternIncreasingNumbers();
                break;
            case 7:
                printTrianglePatternIncreasingNumbersLineWise();
                break;
            case 8:
                printTrianglePatternSecondVersion();
                break;
            case 9:
                printReverseTriangle();
                break;
            case 10:
                starSquarePattern();
                break;
            case 11:
                printStarTriangle();
                break;
            case 12:
                cout << "Exiting the program.\n";
                return 0;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }
    while (true);

    return 0;
}