#include<iostream>
using namespace std;

/*
    Introduction to Programming

    This is a simple C++ program that demonstrates basic input and output operations.
    Basic structure of a C++ program is illustrated here.
    It prompts the user to enter their name and age, then displays a greeting message.

        - Lines starting with # are preprocessor directives.
        - 'using namespace std;' allows us to use standard library features without prefixing them with 'std::'.
        - The 'main' function is the entry point of the program.

    C++ Language Standard: C++14
*/

int main() {
    string name;
    int age;

    // Prompt user for their name
    cout << "Enter your name: ";
    cin >> name;

    // Prompt user for their age
    cout << "Enter your age: ";
    cin >> age;

    // Display greeting message
    cout << "Hello, " << name << "! You are " << age << " years old." << endl;

    return 0;
}