#include <iostream>
using namespace std;

/*
    sqayDigits() Function
        This function takes an integer number as input and prints each digit of the number in words using recursion.
    
    Arguments:
        number : An integer whose digits are to be printed in words.
    
    Returns:
        None (prints the digits in words to the console).

    Approach:
        The function uses recursion to process each digit of the number from the most significant to the least significant:
            - If the number is less than or equal to 0, the function returns (base case).
            - It defines a mapping of digits (0-9) to their corresponding words.
            - It recursively calls itself with the number divided by 10 to process the next digit.
            - After returning from the recursive call, it prints the word corresponding to the last digit (number % 10).

    Time Complexity: O(d) where d is the number of digits in the number.
    Space Complexity: O(d) due to recursive call stack.
*/

void sayDigits(int number) {

    if (number <= 0)
        return;
    
    string map[10] = {"Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};

    sayDigits(number/10);
    
    cout << map[number%10] << " ";
}

// -------------------------------------------------MAIN FUNCTION-------------------------------------------------

int main () {
    int n;

    cout << "Enter a number: ";
    cin >> n;

    sayDigits(n);

    return 0;
}