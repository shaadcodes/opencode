#include<iostream>
using namespace std;

/*
    switchCaseDemo Program

    Approach:
        Use a switch statement to handle different cases based on the value of choice
        For each case, print a corresponding message
        Include a default case to handle invalid choices
*/

// ----------------------------------------------MAIN FUNCTION--------------------------------------

int main() {
    int choice;
    cout << "Enter your choice (1-3): ";
    cin >> choice;

    switch (choice) {
        case 1:
            cout << "You selected option 1." << endl;
            break;
        case 2:
            cout << "You selected option 2." << endl;
            break;
        case 3:
            cout << "You selected option 3." << endl;
            break;
        default:
            cout << "Invalid choice!" << endl;
    }
    return 0;
}