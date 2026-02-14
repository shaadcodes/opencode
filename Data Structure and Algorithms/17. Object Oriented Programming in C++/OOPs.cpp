#include <iostream>
using namespace std;

class Empty
{
    // Empty Class to demnstrate size of empty class
};

/*
    Student class

    Attributes:
        - name (public)
        - age (public)
        - rollNumber (public)
        - internalGrade (private)
        
    Methods:
        - display() (public)
        - setInternalGrade() (public)
        - getInternalGrade() (public)
*/

class Student
{
private:
    // Private members can only be accessed within the class
    char internalGrade;

public:
    string name;
    int age;
    int rollNumber;
    static int studentCount; // Static member to keep track of number of students

    Student()
    {
        // Default constructor
        cout << "Constructor called..." << endl;
        name = "Unknown";
        age = 0;
        rollNumber = 0;
        internalGrade = 'F';
    }

    Student (string name, int age, int rollNumber)
    {
        // Parameterized constructor
        cout << "Parameterized Constructor called..." << endl;
        this->name = name;
        this->age = age;
        this->rollNumber = rollNumber;
        internalGrade = 'F';
    }

    void display()
    {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Roll Number: " << rollNumber << endl;
    }

    void setInternalGrade(char grade)
    {
        internalGrade = grade;
    }

    char getInternalGrade()
    {
        return internalGrade;
    }

    static void incrementStudentCount(void)
    {
        studentCount++;
    }

    static void displayStudentCount(void)
    {
        cout << "Total Students: " << studentCount << endl;
    }

    ~Student()
    {
        // Destructor
        cout << "Destructor called for " << name << endl;
    }
};

// Initialize static member outside the class
int Student::studentCount = 0;

// -----------------------------------------MAIN FUNCTION-----------------------------------------

int main()
{
    Student Alice, Bob;

    Alice.name = "Alice";
    Alice.age = 20;
    Alice.rollNumber = 101;
    Alice.setInternalGrade('A');
    Student::studentCount++; // Increment student count for Alice

    cout << "Student Details:" << endl;
    Alice.display();
    cout << "Internal Grade: " << Alice.getInternalGrade() << endl;
    cout << "Size of Student object: " << sizeof(Alice) << " bytes" << endl;
    Alice.displayStudentCount();

    Bob.name = "Bob";
    Bob.age = 22;
    Bob.rollNumber = 102;
    Bob.setInternalGrade('B');
    Student::studentCount++; // Increment student count for Bob

    cout << "\nStudent Details:" << endl;
    Bob.display();
    cout << "Internal Grade: " << Bob.getInternalGrade() << endl;
    cout << "Size of Student object: " << sizeof(Bob) << " bytes" << endl;
    Bob.displayStudentCount();

    Empty emptyObject;
    cout << endl << "Size of Empty class: " << sizeof(Empty) << " bytes" << endl;
    cout << endl << "Size of Empty class object: " << sizeof(emptyObject) << " bytes" << endl;

    return 0;
}