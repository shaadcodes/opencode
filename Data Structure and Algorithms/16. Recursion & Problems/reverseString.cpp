#include <iostream>
using namespace std;

/*
    reversePhrase() Function

    Return type - void

    Arguments
        1. String reference phrase
        2. Integer start
        3. Integer end

    Approach
        Base case: If start index is greater than end index, return (string is fully reversed)
        Recursive case: Swap characters at start and end indices, then call reversePhrase with incremented start index and decremented end index
        
    Time Complexity: O(n) where n is the length of the string
    Space Complexity: O(n) due to recursive call stack
*/

void reversePhrase(string& phrase, int start, int end)
{   
    if (start > end)
        return;

    swap(phrase[start++], phrase[end--]);
    reversePhrase(phrase, start, end);
}

// -----------------------------------------------MAIN FUNCTION-------------------------------------------------

int main()
{
    string phrase = "Hello, World!";

    // cout << "Enter the string you want to reverse: ";
    // cin >> phrase;

    reversePhrase(phrase, 0, phrase.length() - 1);
    cout << phrase;
}