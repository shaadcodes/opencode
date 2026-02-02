#include <iostream>
#include <vector>
#include <string>
using namespace std;

/*
    solve() Function

    Return type - void

    Arguments:
        1. String str
        2. String outputString
        3. Integer index
        4. Reference to vector of strings answerString

    Approach:
        Base case: If index is greater than or equal to size of str, push outputString to answerString if it's not empty and return
        Recursive case 1: Call solve() without including the current character at index
        Recursive case 2: Include the current character at index in outputString and call solve()
    
    Time Complexity: O(2^n) where n is the number of characters in str
    Space Complexity: O(n) due to recursive call stack and outputString
*/

void solve(string str, string outputString, int index, vector<string> & answerString)
{
	if(index >= str.size())
	{
		if(outputString.size() > 0)
			answerString.push_back(outputString);
		return;
	}

	solve(str, outputString, index+1, answerString);

	char element = str[index];
	outputString.push_back(element);
	solve(str, outputString, index+1, answerString);
}

/*
    subsequences() Function

    Return type - vector of strings

    Arguments:
        1. String str

    Approach:
        Initialize answerString to store all subsequences
        Initialize outputString to store current subsequence
        Call solve() with initial index 0
        Return answerString containing all subsequences
    
    Time Complexity: O(2^n) where n is the number of characters in str
    Space Complexity: O(n) due to recursive call stack and outputString
*/

vector<string> subsequences(string str){

	vector<string> answerString;
	string outputString = "";
	int index = 0;

	solve(str, outputString, index, answerString);

	return answerString;
}

/*
    showString() Function

    Return type - void

    Arguments:
        1. Vector of strings arr

    Approach:
        Iterate through each string in arr and print it
*/

void showString(vector<string> arr)
{
    for(string str : arr)
    {
        cout << str << " ";
    }
}

// ------------------------------------------------------MAIN FUNCITION------------------------------------------------------

int main()
{
    string str = "abc";
    vector<string> result = subsequences(str);

    cout << "Subsequences of the string \"" << str << "\":" << endl;
    
    showString(result);

    return 0;
}