#include <iostream>
using namespace std;

/*
    countDistinctWays() Function
        This function takes an integer nStairs as input and returns the number of distinct ways to climb to the top of a staircase with nStairs steps, 
        where you can take either 1 step or 2 steps at a time.

    Arguments:
        nStairs : An integer representing the total number of stairs.

    Returns:
        An integer representing the number of distinct ways to reach the top of the staircase.

    Approach:
        The function uses recursion with the following base cases:
            - If nStairs < 0, there are no ways to climb (return 0).
            - If nStairs == 0, there is one way to stay at the ground level (return 1).
        For nStairs > 0, it recursively calculates the number of ways to reach the current stair by summing the ways to reach the two preceding stairs:
            - countDistinctWays(nStairs) = countDistinctWays(nStairs - 1) + countDistinctWays(nStairs - 2)
        The result is taken modulo 1,000,000,007 to handle large numbers.
*/

int countDistinctWays(int nStairs) {

    if (nStairs < 0)
        return 0;

    if (nStairs == 0)
        return 1;

    int answer = countDistinctWays(nStairs - 1) + countDistinctWays(nStairs - 2);

    return answer%1000000007;
}

// -------------------------------------------------MAIN FUNCTION-------------------------------------------------

int main () {
    int nStairs;

    cout << "Enter the number of stairs: ";
    cin >> nStairs;
    cout << "Number of distinct ways to climb to the top: " << countDistinctWays(nStairs) << endl;

    return 0;
}