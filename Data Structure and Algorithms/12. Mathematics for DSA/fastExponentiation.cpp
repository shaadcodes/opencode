#include<iostream>
using namespace std;

/*
    fastExponentiation() Function

    Return type - Integer

    Arguments
        1. Integer base
        2. Integer power

    Approach
        Apply Fast Exponentiation technique (Exponentiation by Squaring)
        Initialize result as 1
        While power is greater than 0
            If power is odd, multiply result with base
            Square the base base
            Divide power by 2 (right shift)
        Return result

    Time Complexity: O(log b)
    Space Complexity: O(1)
*/

int fastExponentiation(int base, int power){
    int answer = 1;
    
    while(power > 0){
        if (power&1){
            answer = base * answer;
        }
        base = base * base;
        power = power >> 1;
    }
    return answer;
}

// ----------------------------------------------MAIN FUNCTION--------------------------------------

int main(){

    int a, b;
    cout << "Enter base and power: ";
    cin >> a >> b;
    cout << a << "^" << b << " is = " << fastExponentiation(a, b) << endl;
    return 0;
}