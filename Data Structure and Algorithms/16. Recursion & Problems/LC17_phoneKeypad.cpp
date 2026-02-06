#include <iostream>
using namespace std;

/*
    solve() Function

    Return type - void

    Arguments:
        1. String digits
        2. String array map
        3. String output
        4. Integer index
        5. Reference to vector of strings answer

    Approach:
        Base case: If index is greater than or equal to length of digits, push output to answer and return
        Recursive case: For each letter corresponding to the current digit, append the letter to output, call solve() for next index, and then remove the last letter from output

    Time Complexity: O(4^n) where n is the number of digits (maximum 4 letters for digit '7' and '9')
    Space Complexity: O(n) due to recursive call stack and output string
*/

void solve(string digits, string *map, string output, int index, vector <string> & answer)
{
    if (index >= digits.length())
    {
        answer.push_back(output);
        return;
    }

    int number = digits[index] - '0';
    string letters = map[number];

    for (int i = 0; i < letters.length(); i++)
    {
        output += letters[i];
        solve(digits, map, output, index+1, answer);
        output.pop_back();
    }
}

/*
    letterCombinations() Function

    Return type - vector of strings

    Arguments:
        1. String digits

    Approach:
        Initialize a mapping of digits to letters
        Initialize answer vector to store combinations
        Initialize output string to store current combination
        Call solve() with initial index 0
        Return answer containing all combinations

    Time Complexity: O(4^n) where n is the number of digits
    Space Complexity: O(n) due to recursive call stack and output string
*/

vector<string> letterCombinations(string digits) 
{
    string map[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector <string> answer;
    string output = "";
    int index = 0;

    solve(digits, map, output, index, answer);
    return answer;
}

// ---------------------------------------------------MAIN FUNCTION-------------------------------------------------

int main()
{
    string digits;

    cout << "Enter the digits: ";
    cin >> digits;
    
    vector <string> result = letterCombinations(digits);

    for (string str : result)
    {
        cout << str << " ";
    }

    return 0;
}