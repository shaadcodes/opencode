#include <iostream>
using namespace std;

/*
    printPrimesInSegments() Function

    Return type - void

    Arguments
        1. Integer high (upper limit up to which primes are to be printed)

    Approach
        Apply the Segmented Sieve of Eratosthenes technique
        Phase 1:
            Find all prime numbers up to √high using simple sieve
            Store these primes in a separate list (rangePrimes)
            Print all primes less than √high
        Phase 2:
            Create a boolean array representing range [√high, high]
            Use primes from Phase 1 to mark multiples as non-prime
            Remaining unmarked numbers in the segment are prime
            Print all primes in the remaining range

    Time Complexity: O(high log log high)
    Space Complexity: O(high)
*/


void printPrimesInSegments(int high)
{
    int low = sqrt(high);
    vector<bool> segments(low, true);
    vector<int> rangePrimes;
    int count = 0;

    // Phase - 1: Find and print all primes up to sqrt(n) using simple sieve

    for (int i = 2; i < low; i++)
    {
        if (segments[i])
        {
            for (int j = i * i; j < low; j += i)
            {
                segments[j] = false;
            }
        }
    }

    for (int i = 2; i < low; i++)
    {
        if (segments[i])
        {   
            cout << i << " ";
            rangePrimes.push_back(i);
        }
    }

    // Phase - 2: Use found primes to mark and print non-primes in segments

    vector<bool> dummy(high-low+1, true);

    for (int i = 0; i < rangePrimes.size(); i++){
        for (int j = rangePrimes[i]*rangePrimes[i]; j <= high; j += rangePrimes[i]){
            if (j - low >= 0){
                dummy[j - low] = false;
            }
        }
    }

    for (int i = 0; i < dummy.size(); i++){
        if (dummy[i]) {
            cout << i+low << " ";
        }
    }

}

// ----------------------------------------MAIN FUNCTION------------------------------------

int main()
{
    int number;
    cout << "Enter a number upto which primes are to be counted: ";
    cin >> number;
    cout << "Number of primes between 0 and " << number << " is: ";
    printPrimesInSegments(number);
    return 0;
}