#include <iostream>
using namespace std;

/* 
    This program demonstrates dynamic memory allocation in C++. 
    It shows how to allocate and deallocate memory using new and delete operators.

    Dynamic Memory Allocation in C++:
        1. Use 'new' operator to allocate memory on the heap.
        2. Use 'delete' operator to deallocate memory when no longer needed.
        3. For arrays, use 'new[]' and 'delete[]' for allocation and deallocation respectively.
*/

/*
    allocateMatrix() Function
        Dynamically allocates memory for a 2D matrix.

    Return Type - void

    Parameters:
        int*** matrix - Triple pointer to hold the address of the 2D matrix.
        int rows - Number of rows in the matrix.
        int cols - Number of columns in the matrix.

    Logic:
        1. Allocate memory for an array of row pointers.
        2. For each row, allocate memory for an array of integers (columns).
*/

void allocateMatrix(int*** matrix, int rows, int cols) {
    *matrix = new int*[rows]; // Allocate memory for row pointers
    for (int i = 0; i < rows; i++) {
        (*matrix)[i] = new int[cols]; // Allocate memory for each row
    }
}

/*
    deallocateMatrix() Function
        Deallocates memory for a 2D matrix.

    Return Type - void

    Parameters:
        int** matrix - Double pointer to the 2D matrix.
        int rows - Number of rows in the matrix.

    Logic:
        1. Deallocate memory for each row.
        2. Deallocate memory for the array of row pointers.
*/

void deallocateMatrix(int** matrix, int rows) {
    for (int i = 0; i < rows; i++) {
        delete[] matrix[i]; // Deallocate each row
    }
    delete[] matrix; // Deallocate row pointers
}

//--------------------------------------------MAIN FUNCTION-------------------------------------

int main() {
    // Dynamically allocate memory for an integer
    int* intPtr = new int; 
    *intPtr = 42; // Assign a value to the allocated memory

    cout << "Dynamically allocated integer value: " << *intPtr << endl;

    // Deallocate the memory
    delete intPtr; 
    intPtr = nullptr; // Set pointer to nullptr after deletion

    // Dynamically allocate memory for an array of integers
    int size = 5;
    int* arrPtr = new int[size]; 

    // Assign values to the array
    for (int i = 0; i < size; i++) {
        arrPtr[i] = i * 10;
    }

    cout << "Dynamically allocated array values: ";
    for (int i = 0; i < size; i++) {
        cout << arrPtr[i] << " ";
    }
    cout << endl;

    // Deallocate the array memory
    delete[] arrPtr; 
    arrPtr = nullptr; // Set pointer to nullptr after deletion

    // Dynamically allocate memory for a 2D matrix
    int rows, cols;
    cout << "Enter number of rows and columns for the matrix: ";
    cin >> rows >> cols;
    int** matrix;
    allocateMatrix(&matrix, rows, cols);

    // Assign values to the matrix
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = i + j;
        }
    }
    cout << "Dynamically allocated matrix values:" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    // Deallocate the matrix memory
    deallocateMatrix(matrix, rows);

    return 0;
}