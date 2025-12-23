
/*
    TOPIC
    2 Dimensional Arrays/Matrices

    DESCRIPTION
    Menu - Driven Program to test out working with 2-D Arrays in C++
    Base Array of Integer Type is predefined with a size of [4 X 4]

    CASE - WISE MENU
        CASE I: Input Functions
                1. inputRowWise()
                2. inputColumnWise()

        CASE II: Output Functions
                1. displayMatrixRowWise()
                2. displayMatrixColumnWise()
                3. displayMatrixLinear()

        CASE III: Find - Sum Operations' Functions
                1. largestRowSum()
                2. largestColumnSum()

        CASE IV: Search Functions
                1. searchInMatrix()
                2. largestElement()
                3. smallestElement()

        main() FUNCTION
*/

#include <iostream>
using namespace std;

// ------------------------------------CASE 1 - Input Functions------------------------------

/*
    inputRowWise() Function

    Return type - void

    Arguments
        1. 2D Array (fixed column size)
        2. Number of rows
        3. Number of columns

    Approach
        Two nested for loops are used
        The outer loop iterates row-wise
        The inner loop iterates column-wise
        Elements are inserted row by row
        This simulates row-wise input traversal of a 2D matrix

    Time Complexity: O(rows × columns)
    Space Complexity: O(1)
*/

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

/*
    inputColumnWise() Function

    Return type - void

    Arguments
        1. 2D Array (fixed column size)
        2. Number of rows
        3. Number of columns

    Approach
        Two nested for loops are used
        The outer loop iterates column-wise
        The inner loop iterates row-wise
        Elements are inserted column by column
        This simulates column-wise input traversal of a 2D matrix

    Time Complexity: O(rows × columns)
    Space Complexity: O(1)
*/

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

/*
    displayMatrixRowWise() Function

    Return type - void

    Arguments
        1. 2D Array (fixed column size)
        2. Number of rows
        3. Number of columns

    Approach
        Two nested for loops are used
        The outer loop iterates through each row
        The inner loop iterates through each column of the current row
        Elements are printed row by row
        After printing each row, a new line is printed

    Time Complexity: O(rows × columns)
    Space Complexity: O(1)
*/

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

/*
    displayMatrixColumnWise() Function

    Return type - void

    Arguments
        1. 2D Array (fixed column size)
        2. Number of rows
        3. Number of columns

    Approach
        Two nested for loops are used
        The outer loop iterates through each column
        The inner loop iterates through each row of the current column
        Elements are printed column by column
        After printing each column, a new line is printed

    Time Complexity: O(rows × columns)
    Space Complexity: O(1)
*/

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

/*
    displayMatrixLinear() Function

    Return type - void

    Arguments
        1. 2D Array (fixed column size)
        2. Number of rows
        3. Number of columns

    Approach
        Two nested for loops are used
        The matrix is traversed completely without formatting rows
        Elements are printed continuously in a linear manner
        No line breaks are added between rows or columns

    Time Complexity: O(rows × columns)
    Space Complexity: O(1)
*/

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

// -----------------------------CASE 3 - Find - Sum Operations' Functions-----------------------

/*
    largestRowSum() Function

    Return type - int

    Arguments
        1. 2D Array (fixed column size)
        2. Number of rows
        3. Number of columns

    Approach
        Two nested for loops are used
        The outer loop iterates through each row
        The inner loop iterates through all columns of the current row
        Sum of elements of each row is calculated
        The maximum row sum is tracked and updated
        Finally, the largest row sum is returned

    Time Complexity: O(rows × columns)
    Space Complexity: O(1)
*/

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

/*
    largestColumnSum() Function

    Return type - int

    Arguments
        1. 2D Array (fixed column size)
        2. Number of rows
        3. Number of columns

    Approach
        Two nested for loops are used
        The outer loop iterates through each column
        The inner loop iterates through all rows of the current column
        Sum of elements of each column is calculated
        The maximum column sum is tracked and updated
        Finally, the largest column sum is returned

    Time Complexity: O(rows × columns)
    Space Complexity: O(1)
*/

int largestColumnSum(int twoDimensionalMatrix[][4], int rows, int columns)
{
    int sum = 0, maxSum = 0;
    for (int columnIndex = 0; columnIndex < columns; columnIndex++)
    {
        sum = 0;
        for (int rowIndex = 0; rowIndex < rows; rowIndex++)
        {
            sum += twoDimensionalMatrix[rowIndex][columnIndex];
        }
        if (sum > maxSum)
            maxSum = sum;
    }
    return maxSum;
}

// --------------------------------CASE 4 - Search Functions-----------------------------

/*
    searchInMatrix() Function

    Return type - void

    Arguments
        1. 2D Array (fixed column size)
        2. Number of rows
        3. Number of columns
        4. Target element to be searched

    Approach
        Two nested for loops are used
        The outer loop iterates through each row
        The inner loop iterates through each column
        Each element is compared with the target value
        If a match is found, its row and column indices are printed

    Time Complexity: O(rows × columns)
    Space Complexity: O(1)
*/

void searchInMatrix(int twoDimensionalMatrix[][4], int rows, int columns, int target)
{
    // int targetIndex = -1;
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

/*
    largestElement() Function

    Return type - int

    Arguments
        1. 2D Array (fixed column size)
        2. Number of rows
        3. Number of columns

    Approach
        The first element of the matrix is assumed as the largest
        Two nested for loops are used to traverse the matrix
        Each element is compared with the current largest value
        If a larger element is found, it is updated
        Finally, the largest element of the matrix is returned

    Time Complexity: O(rows × columns)
    Space Complexity: O(1)
*/

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

/*
    smallestElement() Function

    Return type - int

    Arguments
        1. 2D Array (fixed column size)
        2. Number of rows
        3. Number of columns

    Approach
        The first element of the matrix is assumed as the smallest
        Two nested for loops are used to traverse the matrix
        Each element is compared with the current smallest value
        If a smaller element is found, it is updated
        Finally, the smallest element of the matrix is returned

    Time Complexity: O(rows × columns)
    Space Complexity: O(1)
*/

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

/*
    binarySearchMatrix() Function

    Return type - bool

    Arguments
        1. 2D Array (fixed column size)
        2. Number of rows
        3. Number of columns

    Approach
        Consider the 2D matrix as a single sorted array of size rows × columns
        Convert 1D index to 2D indices using:
        Row index → mid / columns
        Column index → mid % columns
        Search is executed through linear binary search method
        Return true → if the target is found
        Return false → if the target is not found

    Time Complexity: O(log(rows × columns))
    Space Complexity: O(1)
*/

bool binarySearchMatrix(int twoDimensionalArray[][4], int rows, int columns, int target)
{
    int start = 0, end = rows * columns - 1;
    int mid = start + (end - start) / 2;
    while (start <= end)
    {
        int element = twoDimensionalArray[mid / columns][mid % columns];
        if (element == target)
        {
            return true;
        }
        else if (target > element)
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
        mid = start + (end - start) / 2;
    }
    return false;
}

/*
    searchMatrixStairWise() Function

    Return type - bool

    Arguments
        1. 2D Vector (row-wise and column-wise sorted matrix)
        2. Target element to be searched

    Approach
        Start searching from the top-right corner of the matrix
        Compare the current element with the target
        If element equals target → return true
        If element is smaller than target → move down to next row
        If element is greater than target → move left to previous column
        Continue until indices go out of bounds
        Return false → if the target is not found

    Time Complexity: O(rows + columns)
    Space Complexity: O(1)
*/

bool searchMatrixStairWise(int twoDimensionalArray[][4], int rows, int columns, int key)
{
    int rowIndex = 0, columnIndex = columns - 1;
    while (rowIndex < rows && columnIndex >= 0)
    {
        int element = twoDimensionalArray[rowIndex][columnIndex];
        if (element == key)
        {
            return true;
        }
        else if (element < key)
        {
            rowIndex++;
        }
        else
        {
            columnIndex--;
        }
    }
    return false;
}

// ---------------------------------MAIN FUNCTION------------------------------------

/*
    main() Function

    Return type - int

    Purpose
        Acts as the driver function for matrix operations
        Provides a menu-driven interface to perform various operations
        Controls program flow using user choices

    Variables Used
        1. choice       → Used to continue or terminate the program
        2. matrix       → 2D array to store matrix elements
        3. rows         → Number of rows in the matrix
        4. columns      → Number of columns in the matrix
        5. input        → Stores main menu choice
        6. subInt       → Stores sub-menu choice

    Approach
        A do-while loop is used to keep the program running until the user exits
        Menu options are displayed to the user
        A switch-case structure handles the main menu options
        Nested switch-case structures handle sub-menu operations
        Appropriate matrix functions are called based on user input
        Time complexity information is displayed for each operation
        Program exits when the user chooses not to continue

    Time Complexity
        Depends on the selected operation
        Most operations take O(rows × columns)

    Space Complexity
        O(1) extra space (matrix size is fixed)
*/

int main()
{
    char choice;
    int matrix[4][4] = {0}, rows = 4, columns = 4;
    do
    {
        int input, subInt;
        cout << "\n\n1. Take Inputs in Matrices" << endl;
        cout << "2. Display Inputs from Matrices" << endl;
        cout << "3. Find Sum of elements in Matrices" << endl;
        cout << "4. Search in Matrices" << endl;
        cout << "\nEnter your Choice: ";
        cin >> input;
        switch (input)
        {
        case 1:
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
                cout << "\n\nTime Complexity: O(rows × columns)";
                break;
            case 2:
                displayMatrixColumnWise(matrix, rows, columns);
                cout << "\n\nTime Complexity: O(rows × columns)";
                break;
            case 3:
                displayMatrixLinear(matrix, rows, columns);
                cout << "\n\nTime Complexity: O(rows × columns)";
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
                cout << "\n\nTime Complexity: O(rows × columns)";
                break;
            case 2:
                cout << largestColumnSum(matrix, rows, columns);
                cout << "\n\nTime Complexity: O(rows × columns)";
                break;
            default:
                cout << "Wrong Input!";
            }
            break;

        case 4:
            cout << "\n1. Search an Element" << endl;
            cout << "2. Find Largest Element" << endl;
            cout << "3. Find Smallest Element" << endl;
            cout << "4. Apply Binary Search" << endl;
            cout << "4. Apply Staircase Search" << endl;
            cout << "Enter Choice: ";
            cin >> subInt;
            switch (subInt)
            {
                int searchElement;
            case 1:
                cout << "\nEnter an element to search: ";
                cin >> searchElement;
                searchInMatrix(matrix, rows, columns, searchElement);
                cout << "\n\nTime Complexity: O(rows × columns)";
                break;
            case 2:
                cout << largestElement(matrix, rows, columns);
                cout << "\n\nTime Complexity: O(rows × columns)";
                break;
            case 3:
                cout << smallestElement(matrix, rows, columns);
                cout << "\n\nTime Complexity: O(rows × columns)";
                break;
            case 4:
                cout << "\nEnter an element to search: ";
                cin >> searchElement;
                if (binarySearchMatrix(matrix, rows, columns, searchElement))
                {
                    cout << "\nFound!" << endl;
                    cout << "\nTime Complexity: O(log(rows × columns))";
                }
                else
                {
                    cout << "\nNot Found!" << endl;
                    cout << "\nTime Complexity: O(rows × columns)";
                }
                break;
            case 5:
                cout << "\nEnter an element to search: ";
                cin >> searchElement;
                if (searchMatrixStairWise(matrix, rows, columns, searchElement))
                {
                    cout << "\nFound!" << endl;
                    cout << "\nTime Complexity: O(rows + columns)";
                }
                else
                {
                    cout << "\nNot Found!" << endl;
                    cout << "\nTime Complexity: O(rows + columns)";
                }
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