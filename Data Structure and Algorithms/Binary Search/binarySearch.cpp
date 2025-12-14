#include<iostream>
using namespace std;

int binarySearch(int array[], int size, int searchElement){
    int start = 0, end = size - 1;

    while(start <= end){
        int mid = start + (end - start)/2;
        if (array[mid] == searchElement){
            return mid;
        }
        else if (array[mid] < searchElement){
            start = mid + 1;
        }
        else {
            end = mid - 1;
        }
    }
    return -1;
}

int main(){

    int simpleArray[] = {1, 2, 4, 7, 9, 11, 16, 24, 25, 32, 36, 40, 49, 50, 64, 73, 81, 91, 100, 121}, key;

    cout << "\nEnter a number to search between squares of 1 & 11: ";
    cin >> key;
    int index = binarySearch(simpleArray, 20, key);
    if(index != -1){
        cout << "\nFound at: " << index << "th index.\n";
    }
    else {
        cout << "Not Found!";
    }

    return 0;
}