#include <iostream>
using namespace std;

/*
    partition() Function

    Return type - int

    Arguments
        1. Integer pointer array
        2. Integer start
        3. Integer end

    Approach
        Choose a pivot element and rearrange the array such that elements less than the pivot are on the left and elements greater than the pivot are on the right.
        Return the final index of the pivot element after partitioning.

    Time Complexity: O(n) where n is the number of elements being partitioned
    Space Complexity: O(1) as it uses a constant amount of space
*/

int partition(int *array, int start, int end)
{
    int pivot = 0;

    for(int i = 0; i < end; i++)
    {
        if(array[i] < array[start]) pivot++;
    }

    swap(array[start], array[pivot]);

    for(int i = 0; i < pivot; i++)
    {
        if(array[i] > array[pivot])
        {
            for(int j = end; j > pivot; j--)
            {
                if(array[j] < array[pivot])
                    swap(array[i], array[j]);
            }
        }
    }

    return pivot;
}

/*
    quickSort() Function

    Return type - void

    Arguments
        1. Integer pointer array
        2. Integer start
        3. Integer end

    Approach
        Base case: If start index is greater than or equal to end index, return (array is sorted)
        Recursive case: Partition the array and recursively call quickSort on the left and right subarrays
        
    Time Complexity: O(n log n) on average, O(n^2) in the worst case
    Space Complexity: O(log n) due to recursive call stack
*/

void quickSort(int *array, int start, int end)
{
    if(start >= end) return;

    int partIndex = partition(array, start, end);

    quickSort(array, start, partIndex);
    quickSort(array, partIndex+1, end);
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

// ----------------------------------------------------- Main Function --------------------------------------------------

int main()
{
    int array[] = {7, 3, 2, 9, 11, 4, 56, 21, 90, 12, 0, 8};
    int size = sizeof(array)/sizeof(array[0]);

    printArray(array, size);

    quickSort(array, 0, size-1);

    printArray(array, size);
}