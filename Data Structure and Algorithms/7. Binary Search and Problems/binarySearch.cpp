#include<iostream>
using namespace std;

/*
    searchArray() Function

    Return type - int

    Arguments
        1. Integer array (sorted)
        2. Size of the array
        3. Element to be searched

    Approach
        Binary Search algorithm is used
        Two pointers (start and end) are initialized
        The middle element is calculated in each iteration
        If the middle element matches the target, its index is returned
        If the target is greater, search continues in the right half
        If the target is smaller, search continues in the left half
        The process repeats until the element is found or the search space is exhausted
        If the element is not found, -1 is returned

    Time Complexity: O(log n)
    Space Complexity: O(1)
*/

int searchArray(int array[], int size, int searchElement){
    int start = 0, end = size - 1;

    while(start <= end){
        int mid = start + (end - start)/2;
        if (array[mid] == searchElement){
            return mid;
        }
        else if (array[mid] < searchElement){
            start = mid + 1;
        }
        else {
            end = mid - 1;
        }
    }
    return -1;
}

/*
    searchMatrix() Function

    Return type - bool

    Arguments
        1. Vector Matrix (sorted element wise)
        2. Element to be searched

    Approach
        Consider the 2D matrix as a single sorted array of size rows × columns
        Convert 1D index to 2D indices using:
        Row index → mid / columns
        Column index → mid % columns
        Search is executed through linear binary search method
        Return true → if the target is found
        Return false → if the target is not found

    Time Complexity: O(log(rows × columns))
    Space Complexity: O(1)
*/

bool searchMatrix(vector<vector<int>> matrix, int target) {
    if (matrix.empty() || matrix[0].empty())
    return false;

    int rows = matrix.size(), columns = matrix[0].size();
    int start = 0,  end = rows*columns - 1;
    int mid = start + (end - start)/2;
    while (start <= end){
        int element = matrix[mid/columns][mid%columns];
        if (element == target){
            return true;
        }
        else if (target > element){
            start = mid + 1;
        }
        else {
            end = mid - 1;
        }
        mid  = start + (end - start)/2;
    }
    return false;
    }

int main(){

    int simpleArray[] = {1, 2, 4, 7, 9, 11, 16, 24, 25, 32, 36, 40, 49, 50, 64, 73, 81, 91, 100, 121}, arrayKey, matrixKey;
    vector<vector<int>> twoDArray = {{1, 8, 64, 343, 729}, {1331, 4096, 13824, 15625, 32768}, {46656, 64000, 117649, 125000, 262144}, {389017, 531441, 753571, 1000000, 1771561}}, key;

    cout << "\nEnter a number to search between squares of 1 & 11 in 1D Array: ";
    cin >> arrayKey;
    int index = searchArray(simpleArray, 20, arrayKey);
    if(index != -1){
        cout << "\nFound at: " << index << "th index.\n";
    }
    else {
        cout << "Not Found!";
    }

    cout << "\nEnter a number to search between cubes of 1 & 20 in Matrix: ";
    cin >> matrixKey;
    if (searchMatrix(twoDArray, matrixKey)){
        cout << "Found in Matrix!";
    }
    else {
        cout << "Not Found in Matrix!";
    }

    return 0;
}