#include <iostream>
using namespace std;

// --------------------------------------------- Compile Time Polymorphism ---------------------------------------------

/*
    constructorOverload Class

    Data Members
        1. Integer member

    Member Functions
        1. Default constructor to initialize member with default value
        2. Parametrized constructor to initialize member with provided value
        3. Parametrized constructor with two arguments to initialize member with provided value and print it repeatedly for provided repititions

    Approach
        1. Create a class constructorOverload to demonstrate constructor overloading
        2. Implement three constructors with different number of parameters to demonstrate constructor overloading
*/

class constructorOverload
{
    public:

        int member = 101;

        // This default constructor will be called when no arguments are provided while creating an object of the class
        constructorOverload()
        {
            cout << "No Arguments Given, Default Constructor Called..." << endl;
            cout << "Value of member: " << member << endl;
        }

        // This parametrized constructor will be called when one argument is provided while creating an object of the class
        constructorOverload(int newMember)
        {
            cout << "One Argument Provided, Parametrized Constructor Called..." << endl;
            member = newMember;
            cout << "member Value Updated" << endl;
            cout << "New Value of member: " << member << endl;
        }

        // This parametrized constructor will be called when two arguments are provided while creating an object of the class
        constructorOverload(int newMember, int repitition)
        {
            cout << "Two Arguments Provided, Parametrized Constructor With Two Arguments Called..." << endl;
            member = newMember;
            cout << "Repeatedly printing value of member till provided repititions: " << endl;
            for (int i = 0; i < repitition; i++)
            {
                cout << member << endl;
            }
        }
};

/*
    operatorOverload Class

    Data Members
        1. Integer value

    Member Functions
        1. Overloading the unary + operator to print the value of the member variable
        2. Overloading the binary * operator to add the value of the member variable of two objects and print the result

    Approach
        1. Create a class operatorOverload to demonstrate operator overloading
        2. Overload the unary + operator to print the value of the member variable
        3. Overload the binary * operator to add the value of the member variable of two objects and print the result
*/

class operatorOverload
{
    public:

        int value = 0;

        // Overloading the unary + operator to print the value of the member variable
        void operator + ()
        {
            cout << value << endl;
        }

        // Overloading the binary * operator to add the value of the member variable of two objects and print the result
        void operator * (operatorOverload & object)
        {
            int value1 = this -> value;
            int value2 = object.value;
            cout << value1 + value2 << endl;
        }
};

// ----------------------------------------------- Run Time Polymorphism -----------------------------------------------

/*
    Animal Class

    Member Functions
        1. communicate() to print "Communicating..."
*/

class Animal
{
    public:

        void communicate()
        {
            cout << "Communicating..." << endl;
        }
};

/*
    Dog Class

    Member Functions
        1. communicate() to print "Barking..."

    Approach
        1. Create a class Dog which inherits from Animal class using public access specifier
        2. Override the communicate() function of the Animal class in the Dog class to demonstrate run time polymorphism
*/

class Dog : public Animal
{
    public:
        void communicate()
        {
            cout << "Barking..." << endl;
        }
};

/*
    Cat Class

    Member Functions
        1. communicate() to print "Meow..."

    Approach
        1. Create a class Cat which inherits from Animal class using public access specifier
        2. Override the communicate() function of the Animal class in the Cat class to demonstrate run time polymorphism
*/

class Cat : public Animal
{
    public:
        void communicate()
        {
            cout << "Meow..." << endl;
        }
};

// -------------------------------------------------- MAIN FUNCTION ---------------------------------------------------

int main()
{

// --------------------------------------------- Compile Time Polymorphism ---------------------------------------------

    operatorOverload opr; // operatorOverload object

    opr.value = 10; // Updating value of member variable of operatorOverload class
    opr*opr; // Using overloaded binary * operator to add the value of member variable of opr object with itself and print the result

// ----------------------------------------------- Run Time Polymorphism -----------------------------------------------

    Animal Mammal; // Animal class object
    Dog Labrador; // Dog class object
    Cat Persian; // Cat class object

    Mammal.communicate(); // Calling communicate() function with Animal class object which will call the communicate() function of the Animal class
    Labrador.communicate(); // Calling communicate() function with Dog class object which will call the overridden communicate() function of the Dog class
    Persian.communicate(); // Calling communicate() function with Cat class object which will call the overridden communicate() function of the Cat class

    return 0;
}