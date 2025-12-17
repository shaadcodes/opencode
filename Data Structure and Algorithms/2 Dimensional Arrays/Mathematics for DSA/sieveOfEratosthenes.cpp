#include <iostream>
using namespace std;

/*
    countPrimes() Function

    Return type - int

    Arguments
        1. Integer n (upper limit, non-inclusive)

    Approach
        Use Sieve of Eratosthenes technique
        Create a boolean vector of size n + 1 initialized as true
        Iterate from 2 to √n
        If current index is marked prime:
            Mark all its multiples (starting from i × i) as non-prime
        After marking, iterate again from 2 to n - 1
        Count all indices still marked as prime
        Return the count of prime numbers less than n

    Time Complexity: O(n log log n)
    Space Complexity: O(n)
*/

int countPrimes(int n)
{
    vector<bool> vec(n + 1, true);
    int count = 0;
    for (int i = 2; i * i < n; i++)
    {
        if (vec[i])
        {
            for (int j = i * i; j < n; j += i)
            {
                vec[j] = false;
            }
        }
    }
    for (int i = 2; i < n; i++)
    {
        if (vec[i])
            count++;
    }
    return count;
}

// ----------------------------------------MAIN FUNCTION------------------------------------

int main()
{
    int number;
    cout << "Enter a number upto which primes are to be counted: ";
    cin >> number;
    cout << "Number of primes between 0 and " << number << " is: " << countPrimes(number) << endl;
    return 0;
}