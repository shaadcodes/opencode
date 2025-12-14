#include <iostream>
using namespace std;

// ------------------------------------CASE 1 - Input Functions------------------------------
void inputRowWise(int twoDimensionalMatrix[][4], int rows, int columns)
{
    for (int rowIndex = 0; rowIndex < rows; rowIndex++)
    {
        for (int columnIndex = 0; columnIndex < columns; columnIndex++)
        {
            cin >> twoDimensionalMatrix[rowIndex][columnIndex];
        }
    }
}
void inputColumnWise(int twoDimensionalMatrix[][4], int rows, int columns)
{
    for (int columnIndex = 0; columnIndex < columns; columnIndex++)
    {
        for (int rowIndex = 0; rowIndex < rows; rowIndex++)
        {
            cin >> twoDimensionalMatrix[rowIndex][columnIndex];
        }
    }
}

// --------------------------------------CASE 2 - Output Functions------------------------------
void displayMatrixRowWise(int twoDimensionalMatrix[][4], int rows, int columns)
{
    for (int rowIndex = 0; rowIndex < rows; rowIndex++)
    {
        for (int columnIndex = 0; columnIndex < columns; columnIndex++)
        {
            cout << twoDimensionalMatrix[rowIndex][columnIndex] << " ";
        }
        cout << endl;
    }
}
void displayMatrixColumnWise(int twoDimensionalMatrix[][4], int rows, int columns)
{
    for (int columnIndex = 0; columnIndex < columns; columnIndex++)
    {
        for (int rowIndex = 0; rowIndex < rows; rowIndex++)
        {
            cout << twoDimensionalMatrix[rowIndex][columnIndex] << " ";
        }
        cout << endl;
    }
}
void displayMatrixLinear(int twoDimensionalMatrix[][4], int rows, int columns)
{
    for (int columnIndex = 0; columnIndex < columns; columnIndex++)
    {
        for (int rowIndex = 0; rowIndex < rows; rowIndex++)
        {
            cout << twoDimensionalMatrix[rowIndex][columnIndex] << " ";
        }
    }
}

// -----------------------------CASE 3 - Find Operations' Functions-----------------------
int largestRowSum(int twoDimensionalMatrix[][4], int rows, int columns)
{
    int sum = 0, maxSum = 0;
    for (int rowIndex = 0; rowIndex < rows; rowIndex++)
    {
        sum = 0;
        for (int columnIndex = 0; columnIndex < columns; columnIndex++)
        {
            sum += twoDimensionalMatrix[rowIndex][columnIndex];
        }
        if (sum > maxSum)
            maxSum = sum;
    }
    return maxSum;
}
int largestColumnSum(int twoDimensionalMatrix[][4], int rows, int columns)
{
    int sum = 0, maxSum = 0;
    for (int columnIndex = 0; columnIndex < rows; columnIndex++)
    {
        sum = 0;
        for (int rowIndex = 0; rowIndex < columns; rowIndex++)
        {
            sum += twoDimensionalMatrix[rowIndex][columnIndex];
        }
        if (sum > maxSum)
            maxSum = sum;
    }
    return maxSum;
}

// --------------------------------CASE 4 - Search Functions-----------------------------
void searchInMatrix(int twoDimensionalMatrix[][4], int rows, int columns, int target)
{
    int targetIndex = -1;
    for (int rowIndex = 0; rowIndex < rows; rowIndex++)
    {
        for (int columnIndex = 0; columnIndex < columns; columnIndex++)
        {
            if (twoDimensionalMatrix[rowIndex][columnIndex] == target)
            {
                cout << "Found at Indices: (" << rowIndex << ", " << columnIndex << ")";
            }
        }
    }
}
int largestElement(int twoDimensionalMatrix[][4], int rows, int columns)
{
    int largest = twoDimensionalMatrix[0][0];
    for (int rowIndex = 0; rowIndex < rows; rowIndex++)
    {
        for (int columnIndex = 0; columnIndex < columns; columnIndex++)
        {
            if (twoDimensionalMatrix[rowIndex][columnIndex] > largest)
            {
                largest = twoDimensionalMatrix[rowIndex][columnIndex];
            }
        }
    }
    return largest;
}
int smallestElement(int twoDimensionalMatrix[][4], int rows, int columns)
{
    int smallest = twoDimensionalMatrix[0][0];
    for (int rowIndex = 0; rowIndex < rows; rowIndex++)
    {
        for (int columnIndex = 0; columnIndex < columns; columnIndex++)
        {
            if (twoDimensionalMatrix[rowIndex][columnIndex] < smallest)
            {
                smallest = twoDimensionalMatrix[rowIndex][columnIndex];
            }
        }
    }
    return smallest;
}

// ---------------------------------MAIN FUNCTION------------------------------------
int main()
{
    char choice;
    int matrix[4][4] = {0}, rows = 4, columns = 4;
    do
    {
        int input;
        cout << "\n\n1. Take Inputs in Matrices" << endl;
        cout << "2. Display Inputs from Matrices" << endl;
        cout << "3. Find Sum of elements in Matrices" << endl;
        cout << "4. Search in Matrices" << endl;
        cout << "\nEnter your Choice: ";
        cin >> input;
        switch (input)
        {
        case 1:
            int subInt;
            cout << "\n1. Input Row Wise" << endl;
            cout << "2. Input Column Wise" << endl;
            cout << "Choose: ";
            cin >> subInt;
            if (subInt == 1)
            {
                inputRowWise(matrix, rows, columns);
            }
            else if (subInt == 2)
            {
                inputColumnWise(matrix, rows, columns);
            }
            else
            {
                cout << "Wrong Input!";
            }
            break;

        case 2:
            cout << "\n1. Display Input Row Wise" << endl;
            cout << "2. Display Input Column Wise" << endl;
            cout << "3. Display Input Memory Wise (Linear)" << endl;
            cout << "Enter Choice: ";
            cin >> subInt;
            switch (subInt)
            {
            case 1:
                displayMatrixRowWise(matrix, rows, columns);
                cout << "\n\nTime Complexity: O(nm)";
                break;
            case 2:
                displayMatrixColumnWise(matrix, rows, columns);
                cout << "\n\nTime Complexity: O(nm)";
                break;
            case 3:
                displayMatrixLinear(matrix, rows, columns);
                cout << "\n\nTime Complexity: O(nm)";
                break;

            default:
                cout << "Wrong Input!";
            }
            break;

        case 3:
            cout << "\n1. Find Largest Row Sum" << endl;
            cout << "2. Find Largest Column Sum" << endl;
            cin >> subInt;
            switch (subInt)
            {
            case 1:
                cout << largestRowSum(matrix, rows, columns);
                cout << "\n\nTime Complexity: O(rows)";
                break;
            case 2:
                cout << largestColumnSum(matrix, rows, columns);
                cout << "\n\nTime Complexity: O(columns)";
                break;
            default:
                cout << "Wrong Input!";
            }
            break;

        case 4:
            cout << "\n1. Search an Element" << endl;
            cout << "2. Find Largest Element" << endl;
            cout << "3. Find Smallest Element" << endl;
            cout << "Enter Choice: ";
            cin >> subInt;
            switch (subInt)
            {
            case 1:
                int searchElement;
                cout << "\nEnter an element to search: ";
                cin >> searchElement;
                searchInMatrix(matrix, rows, columns, searchElement);
                cout << "\n\nTime Complexity: O(nm)";
                break;
            case 2:
                cout << largestElement(matrix, rows, columns);
                cout << "\n\nTime Complexity: O(nm)";
                break;
            case 3:
                cout << smallestElement(matrix, rows, columns);
                cout << "\n\nTime Complexity: O(nm)";
                break;
            default:
                cout << "Wrong Input!";
            }
            break;
        default:
            cout << "Choice Error!";
        }
        cout << "\n\nDo you wish to continue? (Y/N): ";
        cin >> choice;
    } while (choice == 'Y' || choice == 'y');

    return 0;
}