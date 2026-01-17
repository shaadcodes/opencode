#include <iostream>
using namespace std;

/*
    sum() Function

    Return type - int

    Arguments
        1. Integer pointer array
        2. Integer sizeOfArray

    Approach
        Base case: If sizeOfArray is 0, return 0
        Recursive case: Return the sum of the first element and the sum of the rest of the array by calling sum on the subarray excluding the first element and reducing sizeOfArray by 1
        
    Time Complexity: O(n) where n is the number of elements in the array
    Space Complexity: O(n) due to recursive call stack
*/

int sum (int *array, int sizeOfArray)
{
    if (sizeOfArray == 0)
        return 0;

    return array[0] + sum(array + 1, sizeOfArray - 1);
}

// -----------------------------------------------MAIN FUNCTION-------------------------------------------------

int main()
{
    int array[] = {3, 5, 7, 12, 43, 21, 78, 2, 1, 9, 10};

    cout << sum(array, 11);
}