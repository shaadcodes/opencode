#include <iostream>
using namespace std;

/* 
    This program demonstrates dynamic memory allocation for jagged arrays in C++. 
    A jagged array is an array of arrays where the inner arrays can have different lengths.
*/

//  --------------------------------------------MAIN FUNCTION-------------------------------------

int main() {
    
    int rows, column;
    cout << "Enter number of rows: ";
    cin >> rows;

    // Dynamically allocate memory for an array of row pointers
    int** jaggedArray = new int*[rows];
    for (int i = 0; i < rows; i++) {
        cout << "Enter number of columns for row " << i + 1 << ": ";
        cin >> column;

        // Dynamically allocate memory for each row with different number of columns
        jaggedArray[i] = new int[column];

        cout << "Enter elements for row " << i + 1 << ": ";
        for (int j = 0; j < column; j++) {
            cin >> jaggedArray[i][j];
        }
    }

    // Display the jagged array
    cout << "The jagged array is:" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < column; j++) {
            cout << jaggedArray[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}