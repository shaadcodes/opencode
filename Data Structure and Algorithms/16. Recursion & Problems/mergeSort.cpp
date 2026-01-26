#include <iostream>
using namespace std;

/*
    merge() Function

    Return type - void

    Arguments
        1. Integer pointer array
        2. Integer start
        3. Integer end

    Approach
        Find mid index, create two temporary arrays for left and right halves
        Merge the two arrays back into the original array in sorted order
        
    Time Complexity: O(n) where n is the number of elements being merged
    Space Complexity: O(n) due to temporary arrays used in merging
*/

void merge(int *array, int start, int end)
{
    int mid = start + (end - start)/2;

    int firstArrayLength = mid - start + 1;
    int secondArrayLength = end - mid;

    int *firstArray = new int[firstArrayLength];
    int *secondArray = new int[secondArrayLength];
    
    int mainIndex = start;
    for(int i = 0; i < firstArrayLength; i++)
    {
        firstArray[i] = array[mainIndex++];
    }
    
    mainIndex = mid+1;
    for(int i = 0; i < secondArrayLength; i++)
    {
        secondArray[i] = array[mainIndex++];
    }

    int firstIndex = 0;
    int secondIndex = 0;
    mainIndex = start;
    
    while(firstIndex < firstArrayLength && secondIndex < secondArrayLength)
    {
        if(firstArray[firstIndex] < secondArray[secondIndex])
        {
            array[mainIndex++] = firstArray[firstIndex++];
        }
        else
        {
            array[mainIndex++] = secondArray[secondIndex++];
        }
    }

    while(firstIndex < firstArrayLength)
    {
        array[mainIndex++] = firstArray[firstIndex++];
    }

    while(secondIndex < secondArrayLength)
    {
        array[mainIndex++] = secondArray[secondIndex++];
    }

    delete [] firstArray;
    delete [] secondArray;
}

/*
    mergeSort() Function

    Return type - void

    Arguments
        1. Integer pointer array
        2. Integer start
        3. Integer end

    Approach
        Base case: If start index is greater than or equal to end index, return (array is sorted)
        Recursive case: Find mid index, call mergeSort on left half and right half, then merge the two halves
        
    Time Complexity: O(n log n) where n is the number of elements in the array
    Space Complexity: O(n) due to temporary arrays used in merging
*/

void mergeSort(int *array, int start, int end)
{
    if (start >= end) return;

    int mid = start + (end - start)/2;

    mergeSort(array, start, mid);
    mergeSort(array, mid+1, end);

    merge(array, start, end);

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
    int array[] = {5, 6, 2, 1, 7, 4, 23, 12, 89, 0};
    int arraySize = sizeof(array)/sizeof(array[0]);

    printArray(array, arraySize);

    mergeSort(array, 0, arraySize-1);

    printArray(array, arraySize);

    return 0;
}