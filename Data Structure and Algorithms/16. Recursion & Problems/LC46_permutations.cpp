#include <iostream>
#include <vector>
using namespace std;

/*
    solve() Function

    Return type - void

    Arguments:
        1. Reference to vector of vector of integers answer
        2. Vector of integers nums
        3. Integer index

    Approach:
        Base case: If index is greater than or equal to length of nums, push nums to answer and return
        Recursive case: For each index from current index to end, swap current index with loop index, call solve() for next index, and then swap back

    Time Complexity: O(n * n!) where n is the number of elements in nums (n! permutations and O(n) time to copy each permutation)
    Space Complexity: O(n) due to recursive call stack
*/

void solve(vector <vector <int>> & answer, vector <int> nums, int index)
{
    if (index >= nums.size())
    {
        answer.push_back(nums);
        return;
    }

    for (int i = index; i < nums.size(); i++)
    {
        swap(nums[i], nums[index]);
        solve(answer, nums, index+1);
        swap(nums[i], nums[index]);
    }
}

/*
    permute() Function

    Return type - vector of vector of integers

    Arguments:
        1. Vector of integers nums

    Approach:
        Initialize answer vector to store permutations
        Initialize index to 0
        Call solve() with initial index 0
        Return answer containing all permutations

    Time Complexity: O(n * n!) where n is the number of elements in nums
    Space Complexity: O(n) due to recursive call stack
*/

vector<vector<int>> permute(vector<int>& nums) {
    vector <vector <int>> answer;
    int index = 0;

    solve(answer, nums, index);

    return answer;
}

// -----------------------------------------------MAIN FUNCTION-------------------------------------------------

int main()
{
    vector <int> nums = {1, 2, 3};
    vector <vector <int>> result = permute(nums);

    for (vector<int> permutation : result)
    {
        for (int num : permutation)
        {
            cout << num << " ";
        }
        cout << ", ";
    }

    return 0;
}