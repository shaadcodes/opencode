#include <iostream>
using namespace std;

/*
    recursiveBinarySearch() Function

    Return type - bool

    Arguments
        1. Integer pointer array
        2. Integer start
        3. Integer end
        4. Integer key

    Approach
        Calculate mid index
        Base case 1: If mid is out of bounds, return false (key not found)
        Base case 2: If element at mid index is equal to key, return true (key found)
        Recursive case 1: If element at mid index is greater than key, search in left subarray
        Recursive case 2: If element at mid index is less than key, search in right subarray
        
    Time Complexity: O(log n) where n is the number of elements in the array
    Space Complexity: O(log n) due to recursive call stack
*/

bool recursiveBinarySearch (int *array, int start, int end, int key)
{
    int mid = start + (end - start)/2;

    if (mid < start || mid > end)
        return false;

    if (array[mid] == key)
        return true;
    
    if (array[mid] > key)
    {
        return recursiveBinarySearch (array, start, mid-1, key);
    }
    else
    {
        return recursiveBinarySearch (array, mid+1, end, key);
    }
}

// -----------------------------------------------MAIN FUNCTION-------------------------------------------------

int main()
{
    int array[] = {1, 4, 9, 13, 16, 25, 30, 36, 49, 64, 81, 100}, key;

    cout << "Enter the number to search for: ";
    cin >> key;

    if (recursiveBinarySearch(array, 0, 11, key))
    {
        cout << "Present!" << endl;
    }
    else 
    {
        cout << "Not Present!" << endl;
    }

    return 0;
}