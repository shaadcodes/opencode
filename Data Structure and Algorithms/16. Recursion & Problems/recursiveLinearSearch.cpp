#include <iostream>
using namespace std;

/*
    recursiveLinearSearch() Function

    Return type - bool

    Arguments
        1. Integer pointer array
        2. Integer sizeOfArray
        3. Integer key

    Approach
        Base case 1: If sizeOfArray is less than 0, return false (key not found)
        Base case 2: If the first element of the array is equal to key, return true (key found)
        Recursive case: Call recursiveLinearSearch on the subarray excluding the first element and reduce sizeOfArray by 1
        
    Time Complexity: O(n) where n is the number of elements in the array
    Space Complexity: O(n) due to recursive call stack
*/

bool recursiveLinearSearch(int *array, int sizeOfArray, int key)
{
    if (sizeOfArray < 0)
        return 0;

    if (array[0] == key)
        return true;

    return recursiveLinearSearch(array+1, sizeOfArray-1, key);
}

// -----------------------------------------------MAIN FUNCTION-------------------------------------------------

int main()
{
    int array[] = {1, 67, 43, 23, 21, 5, 70, 100, 53, 28}, key;

    cout << "Enter an element to search: ";
    cin >> key;

    if (recursiveLinearSearch(array, 10, key))
    {
        cout << "Present!" << endl;
    }
    else
    {
        cout << "Not Present!" << endl;
    }

    return 0;
}