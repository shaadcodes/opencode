/*
    Character Arrays

    - finding length of a character array
        findLength() Function
            return type: int
            arguments: pointer to a character array

        Approach/
            Initializing a 'count' variable to count elements
            Traversing all elements using a for loop
                for loop starts from 0 index till '\0' is encountered
                Incrementing 'count' by 1 to record a traversed element
            returning the 'count'

        Time Complexity: O(n), where 'n' is the number of elements in character array
        Space Complexity: O(1)

    - reversing a character array
        reverse() Function
            return type: char* 
            arguments: pointer to a character array
            
        Approach/
            Two-Pointer approach | in-place modification
            'start' initialized to 0
            'end' initialized to last element's index in character array
            implementing a while loop which executes till 'start' is smaller than 'end'
                swapping the elements at 'start' and 'end' indices
                increasing 'start' by 1
                decreasing 'end' by 1
            returning the modified array

        Time Complexity: O(n), where 'n' is the number of elements in character array
        Space Complexity: O(1)
*/

#include <iostream>
#include <algorithm>
using namespace std;

// Function to find length of a character array
int findLength(char name[])
{
    int count = 0;

    for (int i = 0; name[i] != '\0'; i++)
    {
        count++;
    }

    return count;
}

// Function to reverse a character array
char *reverse(char string[])
{
    int start = 0, end = findLength(string) - 1;

    while (start < end)
    {
        swap(string[start++], string[end--]);
    }

    return string;
}

int main()
{
    char name[20];

    cout << "Enter your name: ";
    cin.getline(name, 20);
    cout << "Your name is " << findLength(name) << " characters long.\n";
    cout << "Reverse of your name is: " << reverse(name) << endl;

    return 0;
}