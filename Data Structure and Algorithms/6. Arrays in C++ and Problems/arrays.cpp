#include <iostream>
using namespace std;

/*
    Simple Use of Arrays

    Approach:
        Demonstrate basic operations on arrays including input, output, and simple computations
        Use functions to modularize code for better readability and reusability
*/

/*
    getMax() Function
    Return type - int
    Arguments
        1. int arr[] - Array of integers
        2. int size - Size of the array

    Approach
        Initialize maxVal with the first element of the array
        Loop through the array starting from the second element
        If the current element is greater than maxVal, update maxVal
        After the loop, return maxVal
*/

int getMax(int arr[], int size)
{
    int maxVal = arr[0];
    for (int i = 1; i < size; i++)
    {
        if (arr[i] > maxVal)
        {
            maxVal = arr[i];
        }
    }
    return maxVal;
}

/*
    linearSearch() Function
    Return type - int

    Arguments
        1. int arr[] - Array of integers
        2. int size - Size of the array
        3. int key - Element to search for

    Approach
        Loop through the array
        If the current element matches the key, return its index
        If the loop ends without finding the key, return -1
*/

int linearSearch(int arr[], int size, int key)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == key)
        {
            return i; // Return index if found
        }
    }
    return -1; // Return -1 if not found
}

/*
    reverseArray() Function
    Return type - void

    Arguments
        1. int arr[] - Array of integers
        2. int size - Size of the array

    Approach
        Use two pointers, one starting at the beginning and the other at the end of the array
        Swap the elements at these pointers
        Move the pointers towards each other until they meet in the middle
*/

void reverseArray(int arr[], int size)
{
    int start = 0;
    int end = size - 1;
    while (start < end)
    {
        // Swap elements
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        // Move pointers
        start++;
        end--;
    }
}

// ----------------------------------------------MAIN FUNCTION--------------------------------------

int main()
{
    const int SIZE = 5;
    int numbers[SIZE];
    int sum = 0;

    // Input elements into the array
    cout << "Enter " << SIZE << " integers:" << endl;
    for (int i = 0; i < SIZE; i++)
    {
        cin >> numbers[i];
    }

    // Display elements of the array
    cout << "You entered:" << endl;
    for (int i = 0; i < SIZE; i++)
    {
        cout << numbers[i] << " ";
        sum += numbers[i]; // Calculate sum
    }
    cout << endl;

    // Display sum of the elements
    cout << "Sum of the entered integers: " << sum << endl;

    // Find and display the maximum element
    int maxElement = getMax(numbers, SIZE);
    cout << "Maximum element: " << maxElement << endl;

    // Search for an element
    int key;
    cout << "Enter an integer to search for: ";
    cin >> key;
    int index = linearSearch(numbers, SIZE, key);
    if (index != -1)
    {
        cout << "Element " << key << " found at index " << index << "." << endl;
    }
    else
    {
        cout << "Element " << key << " not found in the array." << endl;
    }

    // Reverse the array
    reverseArray(numbers, SIZE);
    cout << "Reversed array:" << endl;
    for (int i = 0; i < SIZE; i++)
    {
        cout << numbers[i] << " ";
    }
    cout << endl;

    return 0;
}