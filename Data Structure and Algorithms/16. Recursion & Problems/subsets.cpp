#include <iostream>
#include <vector>
using namespace std;

/*
    solve() Function

    Return type - void

    Arguments:
        1. Vector of integers nums
        2. Vector of integers outputArray
        3. Integer index
        4. Reference to vector of vector of integers answerArray

    Approach:
        Base case: If index is greater than or equal to size of nums, push outputArray to answerArray and return
        Recursive case 1: Call solve() without including the current element at index
        Recursive case 2: Include the current element at index in outputArray and call solve()
    
    Time Complexity: O(2^n) where n is the number of elements in nums
    Space Complexity: O(n) due to recursive call stack and outputArray
*/

void solve(vector<int> nums, vector<int> outputArray, int index, vector<vector<int>> & answerArray)
{
    if(index >= nums.size())
    {
        answerArray.push_back(outputArray);
        return;
    }

    solve(nums, outputArray, index+1, answerArray);

    int element = nums[index];
    outputArray.push_back(element);
    solve(nums, outputArray, index+1, answerArray);
}

/*
    subsets() Function

    Return type - vector of vector of integers

    Arguments:
        1. Vector of integers nums

    Approach:
        Initialize answerArray to store all subsets
        Initialize outputArray to store current subset
        Call solve() with initial index 0
        Return answerArray containing all subsets
    
    Time Complexity: O(2^n) where n is the number of elements in nums
    Space Complexity: O(n) due to recursive call stack and outputArray
*/

vector<vector<int>> subsets(vector<int>& nums)
{
    vector<vector<int>> answerArray;
    vector<int> outputArray;
    int index = 0;

    solve(nums, outputArray, index, answerArray);
    
    return answerArray;
}

/*
    void showSets(vector<vector<int>> sets)

    Return type - void

    Arguments:
        1. Vector of vector of integers sets

    Approach:
        Iterate through each set in sets
        Print each element of the set
    
    Time Complexity: O(m*k) where m is the number of subsets and k is the average size of each subset
    Space Complexity: O(1)
*/

void showSets(vector<vector<int>> sets)
{
    for(vector<int> set : sets)
    {
        cout << "{ ";
        for(int element : set)
        {
            cout << element << " ";
        }
        cout << "}, ";
    }
}

// -----------------------------------------------MAIN FUNCTION-------------------------------------------------

int main()
{
    vector<int> nums = {1, 2, 3};

    cout << "Subsets are:" << endl;

    showSets(subsets(nums));

    return 0;
}