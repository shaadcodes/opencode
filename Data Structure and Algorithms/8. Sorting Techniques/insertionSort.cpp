#include <iostream>
using namespace std;

/*
    insertionSort() Function
        Selection Sort algorithm sorts an array by repeatedly picking the next element
        and inserting it into its correct position among the previously sorted elements

    Return type - void

    Arguments
        1. int arr[] - Array of integers
        2. int size - Size of the array

    Approach
        Iterate from the second element to the last element of the array
        For each element (key), compare it with the elements before it
        Shift all elements that are greater than the key to one position ahead
        Insert the key at its correct position
*/

void insertionSort(int arr[], int size)
{
    for (int i = 1; i < size; i++)
    {
        int key = arr[i];
        int j = i - 1;
        // Move elements of arr[0..i-1], that are greater than key,
        // to one position ahead of their current position
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

// ------------------------------------------MAIN FUNCTION---------------------------------

int main() {
    const int SIZE = 5;
    int numbers[SIZE];

    cout << "Enter " << SIZE << " integers:" << endl;
    for (int i = 0; i < SIZE; i++)
    {
        cin >> numbers[i];
    }

    insertionSort(numbers, SIZE);

    cout << "Sorted array in ascending order:" << endl;
    for (int i = 0; i < SIZE; i++)
    {
        cout << numbers[i] << " ";
    }
    cout << endl;

    return 0;
}