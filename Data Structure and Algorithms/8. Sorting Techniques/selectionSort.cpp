#include <iostream>
using namespace std;

/* 
    selectionSort() Function
        Sorts an array in ascending order using the selection sort algorithm
        Selection sort divides the array into a sorted and an unsorted region
        It repeatedly selects the smallest element from the unsorted region and moves it to the end of the sorted region

    Return type - void

    Arguments
        1. int arr[] - Array of integers
        2. int size - Size of the array

    Approach
        Use two nested for loops
        The outer loop iterates through each element of the array
        The inner loop finds the minimum element in the unsorted portion of the array
        Swap the found minimum element with the first element of the unsorted portion
*/

void selectionSort(int arr[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < size; j++)
        {
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }
        // Swap elements
        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
}

// ----------------------------------------------MAIN FUNCTION--------------------------------------

int main()
{
    const int SIZE = 5;
    int numbers[SIZE];

    cout << "Enter " << SIZE << " integers:" << endl;
    for (int i = 0; i < SIZE; i++)
    {
        cin >> numbers[i];
    }

    selectionSort(numbers, SIZE);

    cout << "Sorted array in ascending order:" << endl;
    for (int i = 0; i < SIZE; i++)
    {
        cout << numbers[i] << " ";
    }
    cout << endl;

    return 0;
}