// This header file is also an example of encapsulation as it contains both data members and member functions together
#include <iostream> 
using namespace std;

// Encapsulation of Data Members and Member Functions together
class Capsule
{
    public:

        string redPills = "Red Pills", bluePills = "Blue Pills"; // Data Members

        // Member Functions
        void pills ()
        {
            cout << redPills << " + " << bluePills << endl;
        }
};

// ------------------------------------------------- MAIN FUNCTION --------------------------------------------------

int main()
{
    Capsule newCapsule; // Object of the class Capsule is created which has access to both data members and member functions of the class

    newCapsule.pills(); // Accessing the member function which in turn accesses the data members of the class
}