#include <iostream>
using namespace std;

/*
    bubbleSort() Function

    Return type - void

    Arguments
        1. Integer pointer array
        2. Integer start
        3. Integer size

    Approach
        Base case: If start index is greater than or equal to size, return (array is sorted)
        Recursive case 1: If element at start index is less than element at start+1 index, call bubbleSort with incremented start index
        Recursive case 2: If element at start index is greater than element at start+1 index, swap the elements and call bubbleSort with incremented start index
        
    Time Complexity: O(n^2) where n is the number of elements in the array
    Space Complexity: O(n) due to recursive call stack
*/

void bubbleSort(int *array, int start, int size)
{
    if (start >= size)
        return;

    if (array[start] < array[start+1])
        bubbleSort(array, start+1, size);

    if(array[start] > array[start+1])
        swap(array[start], array[start+1]);

    bubbleSort(array, start+1, size);
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

    cout << endl << endl;

    return;
}

// -----------------------------------------------MAIN FUNCTION-------------------------------------------------

int main()
{
    int simpleArray[] = {1, 6, 2, 11, 7, 13, 90, 10};

    printArray(simpleArray, 8);

    cout << "After bubble sort: " << endl;

    bubbleSort(simpleArray, 0, 8);
    printArray(simpleArray, 8);
}