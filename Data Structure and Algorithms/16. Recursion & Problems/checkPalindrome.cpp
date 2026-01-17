#include <iostream>
using namespace std;

/*
    checkPalindrome() Function

    Return type - bool

    Arguments
        1. String str
        2. Integer start
        3. Integer end

    Approach
        Base case 1: If start index is greater than or equal to end index, return true (all characters matched)
        Base case 2: If characters at start and end indices do not match, return false
        Recursive case: Call checkPalindrome with incremented start index and decremented end index
        
    Time Complexity: O(n) where n is the length of the string
    Space Complexity: O(n) due to recursive call stack
*/

bool checkPalindrome(string str, int start, int end)
{
    if (start >= end)
        return true;

    if (str[start] != str[end])
        return false;

    return checkPalindrome(str, ++start, --end);
}

// -----------------------------------------------MAIN FUNCTION-------------------------------------------------

int main()
{
    string phrase = "noone";

    if(checkPalindrome(phrase, 0, phrase.length() - 1))
    {
        cout << phrase << " is Palindrome";
    }
    else
    {
        cout << phrase << " is not Palindrome";
    }

    return 0;
}