#include <iostream>
using namespace std;

// --------------------------------------------- Single-Level Inheritance ---------------------------------------------

/*
    Parent Class

    Data Members
        1. Integer parentAge
        2. String parentName

    Member Functions
        1. printParent() to print the data members of the Parent class
*/

class Parent
{
    int parentAge = 50;

    public:
        string parentName;
        void printParent()
        {
            cout << "Parent Name: " << parentName << ", " << "Parent Age: " << parentAge << endl;
        }
};

/*
    Child Class

    Data Members
        1. Integer childAge
        2. String childName

    Member Functions
        1. printChild() to print the data members of the Child class

    Approach
        1. Create a class Child which inherits from Parent class using public access specifier
        2. Access the data members and member functions of Parent class with Child class object
*/

class Child : public Parent 
{
    int childAge = 20;

    public:

        string childName;
        void printChild()
        {
            cout << "Child Name: " << childName << ", " << "Child Age: " << childAge << endl;
        }
};

// --------------------------------------------- Multi-Level Inheritance ---------------------------------------------

/*
    Creature Class

    Data Members
        1. String birthDay
        2. String deathDay

    Member Functions
        1. printBirthDay() to print the birthDay of the creature
        2. printDeathDay() to print the deathDay of the creature
*/

class Creature
{
    public:

        string birthDay, deathDay;

        void printBirthDay()
        {
            cout << "Birthday is: " << birthDay << endl;
        }

        void printDeathDay()
        {
            cout << "Deathday is: " << deathDay << endl;
        }
};

/*
    Animal Class

    Data Members
        1. Integer age

    Member Functions
        1. communicate() to print "Communicating..."
        2. eat() to print "Eating..."
        3. printAge() to print the age of the animal

    Approach
        1. Create a class Animal which inherits from Creature class using public access specifier
        2. Access the data members and member functions of Creature class with Animal class object
        3. Create a class Dog which inherits from Animal class using public access specifier
        4. Access the data members and member functions of both Creature and Animal classes with Dog class object
*/

class Animal : public Creature
{
    public:

        int age;

        void communicate()
            {
                cout << "Communicating..." << endl;
            }

        void eat()
            {
                cout << "Eating..." << endl;
            }
        
        void printAge()
        {
            cout << age << endl;
        }
};

/*
    Dog Class

    Data Members
        1. Integer limbs
        2. Integer eye

    Member Functions
        1. bark() to print "Barking..."

    Approach
        1. Create a class Dog which inherits from Animal class using public access specifier
        2. Access the data members and member functions of both Creature and Animal classes with Dog class object
*/

class Dog : public Animal
{
    public:

        int limbs = 4, eye = 2;

        void bark()
        {
            cout << "Barking..." << endl;
        }

};

// ----------------------------------------------- Multiple Inheritance -----------------------------------------------

/*
    Mother Class

    Data Members
        1. String motherName
        2. Integer motherAge
        3. String eyeColor

    Member Functions
        1. printMother() to print the data members of the Mother class
*/

class Mother
{
    public:
        string motherName, eyeColor = "Blue";
        int motherAge = 28;

        void printMother()
        {
            cout << endl;
            cout << "Mother Name: " << motherName << endl;
            cout << "Mother Age: " << motherAge << endl;
            cout << "Eye Color: " << eyeColor << endl;
            cout << endl;
        }
};

/*
    Father Class

    Data Members
        1. String fatherName
        2. Integer fatherAge
        3. String eyeColor

    Member Functions
        1. printFather() to print the data members of the Father class
*/

class Father
{
    public:
        string fatherName, eyeColor = "Green";
        int fatherAge = 30;

        void printFather()
        {
            cout << endl;
            cout << "Father Name: " << fatherName << endl;
            cout << "Father Age: " << fatherAge << endl;
            cout << "Eye Color: " << eyeColor << endl;
            cout << endl;
        }
};

/*
    SingleChild Class

    Data Members
        1. String childName
        2. Integer childAge

    Member Functions
        1. printChild() to print the data members of the SingleChild class

    Approach
        1. Create a class SingleChild which inherits from both Mother and Father classes using public access specifier
        2. Access the data members and member functions of both Mother and Father classes with SingleChild class object
*/

class SingleChild : public Mother, public Father
{
    public:
        string childName;
        int childAge = 12;

        void printChild()
        {
            cout << endl;
            cout << "Child Name: " << childName << endl;
            cout << "Child Age: " << childAge << endl;
            cout << endl;
        }
};

// --------------------------------------------- Hierarchial Inheritance ---------------------------------------------

/*
    Grandfather Class

    Data Members
        1. String grandFatherName
        2. Integer grandFatherAge

    Member Functions
        1. printGrandFather() to print the data members of the Grandfather class
*/

class Grandfather
{
    public:
        string grandFatherName;
        int grandFatherAge = 81;

        void printGrandFather()
        {
            cout << endl;
            cout << "Grandfather Name: " << grandFatherName << endl;
            cout << "Grandfather Age: " << grandFatherAge << endl;
            cout << endl;
        }
};

/*
    GrandDaughter Class

    Data Members
        1. String grandDaughterName
        2. Integer grandDaughterAge

    Member Functions
        1. printGrandDaughter() to print the data members of the GrandDaughter class

    Approach
        1. Create a class GrandDaughter which inherits from Grandfather class using public access specifier
        2. Create a class GrandSon which inherits from Grandfather class using public access specifier
        3. Access the data members and member functions of Grandfather class with both GrandDaughter and GrandSon class objects
*/

class GrandDaughter : public Grandfather
{
    public:
        string grandDaughterName;
        int grandDaughterAge = 3;

        void printGrandDaughter()
        {
            cout << endl;
            cout << "Grand Daughter Name: " << grandDaughterName << endl;
            cout << "Grand Daughter Age: " << grandDaughterAge << endl;
            cout << endl;
        }
};

/*
    GrandSon Class

    Data Members
        1. String grandSonName
        2. Integer grandSonAge

    Member Functions
        1. printGrandSon() to print the data members of the GrandSon class

    Approach
        1. Create a class GrandSon which inherits from Grandfather class using public access specifier
        2. Access the data members and member functions of Grandfather class with GrandSon class object
*/

class GrandSon : public Grandfather
{
    public:
        string grandSonName;
        int grandSonAge = 7;

        void printGrandSon()
        {
            cout << endl;
            cout << "Grand Son Name: " << grandSonName << endl;
            cout << "Grand Son Age: " << grandSonAge << endl;
            cout << endl;
        }
};

// ---------------------------------------------- Inheritance Ambiguity -----------------------------------------------

/*
    AmbiguousMaleParent Class

    Data Members
        1. Integer firstVariable

    Member Functions
        1. printVariable() to print the value of firstVariable
*/

class AmbiguousMaleParent
{
    public:
        int firstVariable = 1;

        void printVariable()
        {
            cout << firstVariable << endl;
        }
};

/*
    AmbiguousFemaleParent Class

    Data Members
        1. Integer secondVariable

    Member Functions
        1. printVariable() to print the value of secondVariable
*/

class AmbiguousFemaleParent
{
    public:
        int secondVariable = 0;

        void printVariable()
        {
            cout << secondVariable << endl;
        }
};

/*
    AmbiguousChild Class

    Data Members
        1. Integer exampleVariable 
*/

class AmbiguousChild : public AmbiguousMaleParent, public AmbiguousFemaleParent
{
    int exampleVariable = 10;
};

// -------------------------------------------------- MAIN FUNCTION ---------------------------------------------------

int main()
{

// --------------------------------------------- Single-Level Inheritance ---------------------------------------------

    Child boy; // Child object

    // Accessing Parent class functions with Child object
    boy.childName = "Bob";
    boy.parentName = "Alice";

    boy.printChild();
    boy.printParent();

// --------------------------------------------- Multi-Level Inheritance ---------------------------------------------

    Dog labrador; // Dog object

    // Accessing all class members with Dog object
    labrador.bark();
    labrador.age = 12;
    labrador.printAge();
    labrador.birthDay = "12/06/2020";
    labrador.printBirthDay();

// --------------------------------------------- Multiple Inheritance ---------------------------------------------

    SingleChild Alan; // SingleChild object

    // Accessing Mother & Father class members with SingleChild object
    Alan.childName = "Alan";
    Alan.fatherName = "George";
    Alan.motherName = "Ada";

    Alan.printChild();
    Alan.printFather();
    Alan.printMother();

// --------------------------------------------- Hierarchial Inheritance ---------------------------------------------

    GrandDaughter Mandy; // GrandDaughter object
    GrandSon Billy; // GrandSon object

    // Accessing Grandfather data members using both GrandDaughter & GrandSon objects
    Mandy.grandDaughterName = "Mandy";
    Mandy.grandFatherName = "Tony";
    Billy.grandFatherName = Mandy.grandFatherName;
    Billy.grandSonName = "Billy";

    Mandy.printGrandDaughter();
    Billy.printGrandSon();

    cout << "Mandy's: ";
    Mandy.printGrandFather();

    cout << "Billy's: ";
    Billy.printGrandFather();

// --------------------------------------------- Inheritance Ambiguity ---------------------------------------------

    /*
        Approach:
        
        Inheritance Ambiguity occurs when a child class inherits from two parent classes which have a function with the same name.
        1. Both AmbiguousMaleParent and AmbiguousFemaleParent classes have a function with the same name (printVariable())
        2. When we try to access the printVariable() function with AmbiguousChild object, it creates ambiguity as to which printVariable() function to call
        3. To resolve this ambiguity, we can specify the class name along with the scope resolution operator (::) to indicate which class's function we want to call
    */

    AmbiguousChild object; // AmbiguousChild object

    object.AmbiguousMaleParent::printVariable();
    object.AmbiguousFemaleParent::printVariable();

    return 0;
}