#include <iostream>
using namespace std;

/*
    bubbleSort() Function
        Sorts an array in ascending order using the bubble sort algorithm
        Bubble sort repeatedly steps through the list, compares adjacent elements and swaps them if they are in the wrong order
        The pass through the list is repeated until the list is sorted

    Return type - void

    Arguments
        1. int arr[] - Array of integers
        2. int size - Size of the array

    Approach
        Use two nested for loops
        The outer loop runs for size-1 passes
        The inner loop compares adjacent elements and swaps them if they are in the wrong order
*/

void bubbleSort(int arr[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                // Swap elements
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
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

    bubbleSort(numbers, SIZE);

    cout << "Sorted array in ascending order:" << endl;
    for (int i = 0; i < SIZE; i++)
    {
        cout << numbers[i] << " ";
    }
    cout << endl;

    return 0;
}