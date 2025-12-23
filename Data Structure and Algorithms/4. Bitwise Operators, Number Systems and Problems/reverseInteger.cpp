#include<iostream>
using namespace std;

/*
    reverse() Function

    Arguments: 
        1. Integer x - The number to be reversed

    Returns:
        Integer - The reversed number

    Approach:
        Initialize rev to 0
        While x is not 0
            Get the last digit (rem) of x using modulus operator
            Update rev by multiplying it by 10 and adding rem
            Remove the last digit from x by dividing it by 10
        Return rev
*/

int reverse(int x) {
    int rev = 0;
    while (x != 0){
        int rem = x % 10;
        rev = rev*10 + rem;
        x /= 10;
    }
    return rev;
}

// ----------------------------------------------MAIN FUNCTION--------------------------------------

int main(){
    int number;
    cout << "Enter a number: ";
    cin >> number;
    cout << "Reverse is: " << reverse(number) << endl;
    return 0;
}