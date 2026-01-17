#include <iostream>
using namespace std;

/*
    insertionSort() Function

    Return type - void

    Arguments
        1. Integer pointer array
        2. Integer size

    Approach
        Base case: If size is less than or equal to 1, return (array is sorted)
        Recursive case:
            1. Call insertionSort on the array with size reduced by 1
            2. Store the last element as key and compare it with elements before it
            3. If the previous element is greater than key, shift the previous element one position ahead and place key at its correct position by calling insertionSort again for the reduced size
            
    Time Complexity: O(n^2) where n is the number of elements in the array
    Space Complexity: O(n) due to recursive call stack
*/

void insertionSort(int *arr, int size)
{
    if (size <= 1)
        return;

    insertionSort(arr, size-1);

    int key = arr[size - 1];
    int index = size - 2;

    if (index >= 0 && arr[index] > key)
    {
        arr[index + 1] = arr[index];
        arr[index] = key;
        insertionSort(arr, index + 1);
    }
}

/*
    printArray() Function

    Return type - void

    Arguments
        1. Integer pointer array
        2. Integer size

    Approach
        Iterate through the array and print each element
        
    Time Complexity: O(n) where n is the number of elements in the array
    Space Complexity: O(1) as it uses a constant amount of space
*/

void printArray(int *array, int size)
{

    cout << endl;

    for (int i = 0; i < size; i++)
    {
        cout << array[i] << " ";
    }

    return;
}

// -----------------------------------------------MAIN FUNCTION-------------------------------------------------

int main()
{
    int array[] = {1, 6, 0, 8, 3, 12, 18, 21, 11, 7};
    
    printArray(array, 10);

    insertionSort(array, 10);

    printArray(array, 10);
}