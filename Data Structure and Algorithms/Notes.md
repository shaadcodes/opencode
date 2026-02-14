### 17th December 2025

**LEARNED ABOUT MATHEMATICAL CONCEPTS FOR DATA STRUCTURES AND ALGORITHMS**

Topics Covered

- **Sieve of Eratosthenes**

  Sieve of Eratosthenes is a technique used to eliminate or **sieve - out** the number of comparisons performed by CPU,
  which can be useful to significantly reduce the CPU time for an algorithm.

  Created a C++ program to count prime numbers till 'n' using Sieve of Eratosthenes Technique (refer to "sieveOfEratosthenes.cpp" inside "Mathematics for DSA")

- **Segmented Sieve**

  Segmented sieve technique is polished version of Eratosthenes Sieve technique, optimized for large datasets, which are not possible to compute with Simple Sieve
  Code for Segmented Sieve technique
  (refer to "segmentedSieve.cpp" inside "Mathematics for DSA")  
   (refer at: https://www.geeksforgeeks.org/dsa/segmented-sieve/)

- **GCD (Greatest Common Divisor) / HCF (Highest Common Factor)**

  - Euclidean Algorithm: For any two positive numbers **a** and **b** _(a > b)_: GCD(a, b) = GCD(a-b, b)

    _Euclidean algorithm is a mehtod used to find GCD of two positive integers by subtracting the smaller number by the larger number
    then again, performing the same operation between the obtained resultants until one of them becomes zero, and the remaining
    non zero integer will be the GCD of a & b_

  - Extended Euclidean Algorithm: _ax + by = GCD(a, b)_ where, _x & y_ are obtained by applying Extended Euclidean Algorithm
  - Code of Euclidean Algorithm (refer to "euclidsGCD.cpp" inside "Mathematics for DSA")

  - Relation between LCM & GCD:

    **_LCM(a, b) * GCD(a, b) = a * b_**

    Conceptual in-depth understanding of GCD in Computer Science (refer at: https://www.geeksforgeeks.org/dsa/euclidean-algorithms-basic-and-extended/)

- **Modular Arithmetics**

  Basics of Modular Arithmetics:
  For any two positive numbers **a** and **b**:

  - ((a % m) + (b % m)) % m = (a + b) % m
  - ((a % m) - (b % m)) % m = (a - b) % m
  - ((a % m) _ (b % m)) % m = (a _ b) % m
  - (a / b) % m = (a \* (b^-1)) % m

  (refer at: https://codeforces.com/blog/entry/72527)

  Fast Exponentiation problem:

  Optimizing exponential calculations for large numbers (in range) using modulo  
   (refer to "fastExponentiation.cpp" inside "Mathematics for DSA")

### 20 - 23rd December 2025

**CREATED CLEAN DOCUMENTATION AND PROGRAMS TOPIC-WISE**

Changes in "Data Stuctures And Algorithms"  

- **1 - 13 Folders**  
    - Introduction to Programming  
    - Conditional Statements and Loops  
    - Patterns  
    - Bitwise Operators, Number Systems and Probability  
    - Switch Statements and Functions  
    - Arrays in C++ and Problems  
    - Binary Search and Problems  
    - Sorting Techniques  
    - Standard C++ Template Library  
    - Character Arrays & Strings  
    - 2 Dimensional Arrays  
    - Mathematics for DSA  
    - Pointers in C++ 

### 23rd December 2025

**POINTERS IN C++**

Topics 

- **What?**

    Pointers are variables which store **memory addresses** of other variables
    Size of a pointer is 8 bytes, independant of the type of variable it points to

- **How?**

    Pointers of any specific type can be created using the syntax:  
    <code>type *pointer</code>  
    Example:  
    <code>int *p = &n;</code>  
    & -> Address of operator  
    (this will be read as, "p is a pointer to integer n" or "address of n is stored in p")

- **Why?**

    Pointers are useful to directly work with values by modifying using addresses in functions rather than using
    copy of variables passed
    Pointers are useful in memory management

- **Pointers with Arrays**

    When a pointer to an array is created, the pointer stores the address of the first element of array  
    for a pointer p and an array,  
    such that:  
    <code> *p = array[0] = array; </code>

(Refer to "playingWithPointers.cpp", "doublePointers&operator.cpp" & "pointersWithFunctions.cpp" inside "Pointers in C++")

### 27th December 2025

**DYNAMIC MEMORY ALLOCATION IN C++**

Topics 

- **What is Stack Memory and Heap Memory?**

    When a program is compiled in C++, it brings with it a Stack Memory and a Heap Memory.  

    **Stack Memory:** It is lesser than Heap Memory and the compile-time declared variables and containers  
    specify how much Stack Memory will be allocated to the program.  
    Stack Memory is allocated and deallocated automatically throughout specific scopes of a program.  
    Allocating some memory to stack (Creating variables and containers like arrays etc) is known as Static Memory Allocation.

    **Heap Memory:** Heap Memory is larger in size as compared to Stack Memory.  
    Heap Memory is allocated by run-time requested variables and containers.  

    - Allocating Heap Memory is known as Dynamic Memory Allocation. This is done using 'new' keyword.  
      for allocating 4 bytes of integer at run-time:  

      ```cpp
      new int;  
      new int[sizeOfArray];  // for an array
      ``` 

      This allocates 4 bytes (size of ineteger is 4 bytes) of Heap Memory at run-time.  
      'new int' returns an address to the allocated Heap Memory for an integer, so to store this address, we use a pointer variable of int type, so this allocation of 4 bytes of memory for an integer looks like:  

      ```cpp
        int *addressOfAllocatedMemory = new int;
        int *addressOfAllocatedMemory = new int[sizeOfArray];  // for an array
      ```

    - Deallocating Allocated Memory  
      Allocated Heap Memory is released using 'delete' keyword along with the pointer variable storing the address of the Heap Memory which is to be released.  
      
      Syntax:  
      ```cpp
      delete addressOfAllocatedMemory;
      delete[] addressOfAllocatedArray;  // for an array
      ```

- **Why Dynamic Memory allocation?**

    Dyanmic Memory allocation is the optimized and crash-resistant way of allocation memory at run-time.  
    for example, we want to allocate memory defined by user:  

    ```cpp
      cout << "Enter the size of array: ";
      cin >> sizeOfArray;
      int array[sizeOfArray];
    ```

    This is considered as a BAD Practice. So dynamic memory allocation is used to allocate memory at run-time.  

    ```cpp
        cout << "Enter the size of array: ";  
        cin >> sizeOfArray;  
        int *pointerStoringAddress = new int[sizeOfArray];  
    ```
    This is the proper way of allocating memory dynamically in C++.

- **Allocation in 2-Dimensional Arrays**

    for allocating a 2-D Array dynamically using pointer of pointers (double pointers).  
    This is illustrated by creation and use of a Jagged Array.  

(Refer to "Dynamic Memory Allocation in C++")

### 30th December 2025

**MACROS, GLOBAL VARIABLES, INLINE FUNCTIONS & DEFAULT ARGUMENTS**
(refer to "15. Macros, Global Variables, Inline Functions & Default Arguments")

Topics 

- **Macros**

    Macros are a piece of code which are replaced in the program by the value of macro.  
    To create a macro we use ' #define ' before macro name and assign a value to it.  

    Syntax:  
    <code> #define macroName macroValue  </code>

    Example:  
    <code> #define pi 3.14 </code>

    These macros need to be defined after including the header files at the top of program. (no need of semicolon)  
    Macros do not consume any extra memory space unlike creating variables.  

    (refer to "macros.cpp")

- **Global Variables**

    Global Variables are simple variable declarations outside of any function (main function included).  
    Global variables are declared similarly as simple variables, they are stored in **permanent storage area.**  
    Since, Global variables are variables, they consume memory.  
    Global Variables are not preferred much because their values can be changed accidentally throughout the program which can lead to loss of original value of the variable.  
    Declaring a global variable means it's scope is extended throughout the program.  
    _Declaration:_  

  ```cpp
    #include <iostream>
    using namespace std;
    int globalVariable = 67; // Global Variable Declaration

    int main(){
      // statements
      return 0;
    }
  ```

  (refer to "globalVariables.cpp")

- **Inline Functions**

    Inline functions are defined using the _inline_ keyword.  
    Inline functions are used to **function call overhead** (which means the performance hit caused by calling the function, which means the time taken to call the function by referring to it's definition and creating copies of arguments)  
    By adding the _inline_ keyword to a function, the function call is replaced by the function defintion completely, reducing the function call overhead.  
    The ideal case for making a function inline is when thew function body is smaller (1-line function body)

    (refer to "inlineFunctions.cpp")

- **Default Arguments**

    Default arguments are used when it's not definite that the user may want or not want to provide any value for the function to run.  
    We can say the optional arguments defined in the function are known as default arguments.  
    To define a default argument, assign it a default value while defining it in a function definition.  

    Syntax:  
    <code>return type (datatype value, datatype value = defaultValue);</code>

    Example:  
    <code>void func(int x, int y = 0);</code>

    In this example, if a function call is made like this, _func (4, 5)_, the function will use the provided value for the argument 'y', but if a function call is made like this, _func (9)_, the function will automatically assume the value of argument 'y' to be 0 as assigned by default.  

    (refer to "defaultArguments.cpp")

### 7 - 8th January 2026

**Recursion**
(refer to "16. Recursion & Problems")

Topics 

- **Recursion Basics**

  When a function calls itself, the process is known as **recusrsion** and thus the function is called a recursive function.  

  OR  

  When a function call is made inside its own body, this process is called recursion.  

  OR  

  _When a small case of a problem is solved and to solve the whole problem, the same approach is used for all small parts of the problem to solve the whole problem, this approach is called recursion._  

  There are two mandatory components of recursion for an error free solution,  

    _Base Case:_ A base case is defined to stop the recursion process, if no base case is defined, the recursion goes on till the program is crashed. (example - if (n == 1) return 0;)  

    _Recursive Relation:_ A proper recursive relation is defined to solve the problem. (example - f(a) = f(b) + f(c);)  

  Syntax:  
  ```cpp
    return_type functionName (arguments)
    {
      functionName (arguments);
    }  
  ```

  Example:  
  ```cpp
    int print (int n)
    {
      if (n == 0) return 0; // Base Case
      print (n-1); // Recursive Relation
      cout << n; // Processing
    }
  ```  
  **Head Recursion Vs. Tail Recursion**

  When the recursive call is made before the processing of the function, the recursion is said to be **head recursion**  

  When the recursive call is the last operation in the function, the recursion is said to be **tail recursion**  

  **Problems Solved:**

    -   Calculate power using recursion (refer to "calculatePower.cpp" inside "16. Recursion & Problems")
    -   Check if a string is Palindrome (refer to "checkPalindrome.cpp" inside "16. Recursion & Problems")
    -   Factorial Calculation (refer to "factorial.cpp" inside "16. Recursion & Problems")
    -   Fibonacci Series (refer to "fibonacci.cpp" inside "16. Recursion & Problems")
    -   Rat in a maze problem (refer to "GFG_ratInAMaze.cpp" inside "16. Recursion & Problems")
    -   Letter Combinations of a Phone Number (refer to "LC17_phoneKeypad.cpp" inside "16. Recursion & Problems")
    -   Permutations of a string (refer to "LC46_permutations.cpp" inside "16. Recursion & Problems")
    -   Different ways to climb stairs (refer to "nStairs.cpp" inside "16. Recursion & Problems")
    -   Applied recursive Binary Search (refer to "recursiveBinarySearch.cpp" inside "16. Recursion & Problems")
    -   Applied recursive Bubble Sort (refer to "recursiveBubbleSort.cpp" inside "16. Recursion & Problems")
    -   Applied recursive Insertion Sort (refer to "recursiveInsertionSort.cpp" inside "16. Recursion & Problems")
    -   Applied recursive Linear Search (refer to "recursiveLinearSearch.cpp" inside "16. Recursion & Problems")
    -   Program to reverse an input string using recursion (refer to "reverseString.cpp" inside "16. Recursion & Problems")
    -   Print the digits' names in a given number (refer to "sayDigits.cpp" inside "16. Recursion & Problems")
    -   Subsequences of a string problem (refer to "subsequences.cpp" inside "16. Recursion & Problems")
    -   Subsets of an array problem (refer to "subsets.cpp" inside "16. Recursion & Problems")
    -   Calculate sum of elements in an Array (refer to "sumOfArray.cpp" inside "16. Recursion & Problems")

  **Merge Sort:**  

    Merge sort is a sorting technique which divides the given array into two parts, and recursively sorts the encountered subarrays and merges all the sorted parts into one single, sorted array.

    (refer to "mergeSort.cpp" inside "16. Recursion & Problems")

  **Quick Sort:**  

    Quick sort first creates a partition in the array using a pivot element. A pivot is created by placing the first element of the array to it's correct position, which is determined by finding the number of elements smaller than the first element. Then, a pivot is created by placing the first element to it's correct position and then for sorting, a condition is satisfied i.e. All the elements towards the left of the pivot must be smaller than the pivot and the elements towards the right of the pivot must be greater than the pivot, this process is called 'Partition' as a whole.
    After creating partition, a recursive call is made in the left portion of the pivot and then the right portion and eventually the array gets sorted.

    (refer to "quickSort.cpp" inside "16. Recursion & Problems")

### 11th February 2026

**Time and Space complexity of recursive functions**

  - **Time Complexity**  
  
    To compute time complexity of recursive functions, we create specific _recurrence relations_ (like mathematical equations) to solve and extract the time complexitites.

    Let's say, we have written a function 'f' with input 'n', f(n) and we have to calculate the time complexity of this function.  
    First we refer to the recurrence relation like _f(n) = n * f(n-1)_, say a factorial function (refer to "factorial.cpp" inside "16. Recursion & Problems"), then we create a time complexity equation out of this relation and function working as _T(n) = k + T(n-1)_, where, T(n) is the time required as of input 'n' and 'k' is a constant time required by function for constant computations.  

    Then, we find the same equation for _T(n-1)_, as _T(n-1) = k + T(n-2)_ and continue till we find the equation for the base cases as _T(1) = k + T(0)_ & _T(0) = k_  

    After we collect all of the equations, we add all the equations as:  

    T(n) = k + T(n-1)  
    T(n-1) = k + T(n-2)  
    T(n-2) = k + T(n-3)  
    |  
    |  
    |  
    |  
    T(1) = k + T(0)  
    T(0) = k  
    \+  
    _________________
    T(n) = k * n + k  

    Since, 'k' is a constant time, we neglect 'k' and the overall time complexity becomes **_T(n) = O(n)_**  
    Hence, we can use this approach to find time comlexities of specific functions.

  - **Space Complexity**

    To calculate space complexity of a recursive function, we build and study the function call stack of the recursive function and add up all the space required for each call and any extra space which is not released (deallocated).  

    To do this let's have a function, say factorial (refer to "factorial.cpp" inside "16. Recursion & Problems"), now we first collect the constant extra space for each call.  

    S(n) = k + S(n-1) where, 'k' is the constant extra space required in all conditions so we collect all the call stack equations as:  

    S(n) = k + S(n-1)  
    S(n-1) = k + S(n-2)  
    S(n-3) = k + S(n-4)  
      |  
      |  
      |  
      |  
    S(1) = k + S(0)  
    S(0) = k  
    \+
    ___________________

    S(n) = k * n + k

    Since we neglect the constant terms, we get **_S(n) = O(n)_**  

(refer to "16. Recursion & Problems" & https://www.naukri.com/code360/guided-paths/competitive-programming/content/126222/offering/1476042?leftPanelTabValue=PROBLEM&customSource=studio_nav)

### 12th February 2026

**Object Oriented Programming (OOPs)**

  Object Oriented Programming is used to solve real-world problems and create secure, extensible and easy to maintain programs.
  OOPs has many benefits, which will be discussed with progress.
  
  - **_Classes_**

    Classes are user defined datatypes which can be used to create variables of type _class_, called the objects of the classes. Classes contain data members (class variables) and member functions (class functions). Creation of a class does not consume any memory but only record a blueprint for defining an object, and only objects consume the memory only when declared or created. 

    Example class creation in C++:  

    ```cpp
      class ClassName 
      {
        int dataMember;

        void memberFunction(void)
        {
          return;
        }
      };
    ```
  
  - **_Objects_**

    When a class is created, it's instances can be defined known as _objects_. Objects are real-world entities consisting of some **_attributes_** (data members defined in the class) and **_behaviour_** (memeber functions of the class). These instances can use the data members and member functions of the classes binded in a single entity improving the readabilitiy and security of code.  

    Example creation of objects in C++:  

    ```cpp
      class ClassName 
      {
        int dataMember;

        void memberFunction(void)
        {
          return;
        }
      };

      int main()
      {
        ClassName object1, object2;

        return 0;
      }
    ```

    **To access data defined inside a class using an object we use ' . ' (dot) operator**  
    Example: <code> object1.dataMember = 5; </code>

  - **_Access Modifiers_**

    A key feature of OOPs is that the programs created using OOPs are _secure_. Security and resource sharing in OOPs can be controlled using _Access Modifiers_ which determine who can access the data and members.  

    There are 3 types of access Modifiers:  

      - **_Public_**: Data can be accessed by anyone inside or outside the class.
      - **_Private_**: Data can be accessed only by the class member functions inside the class and to access data outside, the public member functions must be used (i.e data cannot be accessed directly using objects).
      - **_Protected_**: To be discussed later...

    ```cpp
      class Car
      {
        private:
          int issues;

        public:
          char model;
          int price;
      };
    ```

    Now, In the above snippet, the _model_ and _price_ of the Car can be accessed by anyone iside or outside the class because _public:_ access modifier is used but the number of issues in. the model can only be accessed by the user of the class.  

    **By default, all the data inside a class is private**

  - **_Getters & Setters_**

    Getters and Setters are specialized functions (member functions) used to access private data members outside the class.  
    Getters are used to get the data members' values while Setters are used to set or assign values to data members.

    ```cpp
      class Car
      {
        private:
          int issues;

        public:
          char model;
          int price;

          int getIssues()
          {
            return issues;
          }

          void setIssues(int issueCount)
          {
            issues = issueCount;
          }
      };
    ```

    Now, We can access the private _'issue'_ member using getters and setters.

  - **_Memory Consumption of classes and objects_**

    - Empty Class
      
      An empty class consumes 1 byte of memory just to create an identification of it's existence.  
      (Actually classes don't taek up any space, classes are only blueprints for object (instance) definition. Memory is consumed onkly when an object of a specific class is created)

    - Classes with contents
    
      Memory consumption by the objects of a class is determined by the number and size of variables and data structures defined inside the class.

      Example:

    ```cpp
    class Car
    {
      private:
        int issues;

      public:
        char model;
        int price;

        int getIssues()
        {
          return issues;
        }

        void setIssues(int issueCount)
        {
          issues = issueCount;
        }
    };

    ```

    Since this class consists of 3 variables _issues(4 bytes integer), model(1 byte character)_ and _price(4 bytes integer)_ So, when an object of this class is created as <code>Car xuv;</code>, this _xuv_ object, when created, takes up 4 + 1 + 4 = 9 bytes of memory but because of **_memory padding_**, the final size would be 12 bytes instead of 9 bytes.

    Memory padding is applied by compiler to efficiently manage storage and retrieval (accession) of variable inside memory by placing variables in equal memory blocks like 4 + 4 + 4 instead of 4 + 1 + 4, this technique optimizes management of resources in memory and improves efficiency but for a trade-off of more memory consumption. To solve this problem, we use **_Greedy Alignment_** technique where we place the variables in a class in the ascending order of their size so the compiler packs them more tighly in memory blocks.

  - **_Static and Dynamic Allocation_**

    Just like we create variables statically as well as dynamically, we can do same for objects.

    - Static

      <code> Car xuv, thar, sedan; </code>

    - Dynamic

      <code> Car *xuv = new Car; </code>  
      <code> Car *xuv = new Car[5]; </code> (for array)  

    We should access the dynamically allocated objects (using their pointers) either by de-referencing (*objectPointer) the pointers or using the value at (arrow **->**) operator.

    Example:  

    <code> cout << (*xuv).price << endl; </code>  
    <code> cout << xuv -> price << endl; </code>

  - **_Constructors_**

    Constructors are special functions of a class which are automatically invoked upon object creation. Even if there is no constructor function defined inside a class, by defalut a consturctor function is defined and invoked automatically.  

    We can explicitly define our own constructors with specific tasks or to initialize objects upon creation.  
    A constructor has the same name as it's class and no return type.  
    Example:   

    ```cpp
      class Car
      {
        Car ()
        {
          cout << "Car object creaeted..." << endl;
        }
      }
    ```

    Now whenever an object of class _Car_ is created, "Car object is created..." automatically prints on the screen due to automatic constructor call.

    - Parameterized constructors

      Constructors defined by the user which have specific parameters are called parameterized constructors.  

      Example:  <code> ConstructorName (parameterType parameterName) </code>  

      These are generally used to initialize objects while declaration. We can directly assign values to objects while declaring them with the use of parameterized constructors.

      Example:  

    ```cpp
    class Car
    {
      private:
        int issues;

      public:
        char model;
        int price;

        Car (char model, int price)
        {
          this.model = model; // this using dot operator
          this -> price = price; // this using value at operator
        }
    };

    int main()
    {
      Car xuv('C', 800000); // Static
      Car *sedan = new Car('A', 1500000); // Dynamic
    }
    ```

    **"_this_" keyword is used to differentiate between the variables. _this_ keyword stored the address of the current class object (can be used with dot (.) or value at (->) operator)**

    - Copy constructors

      Copy constructors are used to replicate values from a pre defined object to a new object. Copy constructors have an object passed as a parameter.  

    ```cpp
    class Car
    {
      private:
        int issues;

      public:
        char model;
        int price;

        Car (Car& oldCar)
        {
          this.model = oldCar.model;
          this.price = oldCar.price;
        }
    };

    int main()
    {
      Car xuv('C', 800000);
      Car newXuv(xuv); // Method 1
      Car otherXuv = newXuv; // Method 2
    }
    ```

    **Note: There is no need to explicitly create a copy constructor, passing an object as a parameter automatically invokes default copy constrcutor of an object.**

  - **_Shallow VS Deep Copies_**

    Whenever a copy constructor is invoked, the reference of object is passed as a parameter, not the object itself. So, any changes made in one objec reflects in the other object using the previous object as an argument. This is known as a **_Shallow copy_**. 

    Now to avoid this problem and create copies which are independant of changes in each object, we create copies of the data explicitly inside the copy constructor. This copy is known as a **_Deep copy_**.

    **Default copy constructor always creates a shallow copy.**

  - **_Copy Assignment Operator_**

    When an object is created and values are initilized then we can easily copy the values of first object into another using _assignment operator (=)_.  

    Example: <code> object2 = object1; </code>  

    This above piece of code will copy the values from _object1_ to _object2_.

  - **_Destructors_**

    Destructors function similar to constructors in a way that they're called automatically just before moving out of current scope.  
    They look similar to constructors _i.e._ they have the same name as the class and no parameters except that they begin with a tilda sign (~).

    ```cpp
      class Car
      {
        Car () // Constructor
        {
          cout << "Constructor called / Car object creaeted..." << endl;
        }

        ~Car () // Destructor
          cout << "Destructor called / Car object deleted..." << endl;
        }
      }
    ```

    **Constructors and Destructors are automatically defined and called if not explicitly done.**

  - **_static Keyword & static Functions_**

    _static_ keyword is used to declare variables which can be called outside a class without creating any object of the class. _i.e._ static keyword makes the data _static_ (same) for all the objects of the class.  

    Like when we create variables, we can assign different values to different variables but when static variables are defined, only one value is common among the objects _i.e._ all the objects created have the same value.

    when a fucntion is made static, _i.e._ defined with a _static_ keyword, It can only access static variables.  

    ```cpp 
      static int staticVariableName;
      static int staticFunctionName ()
      {
        staticVariableName = value;
      }
    ```

    Static variables are initialized outside the main() function and used with Scope resolution operator (::).  

    Example: <code> int className::staticVariableName = value; </code>, This is initialization.  

    Now to modify or access the value, the syntax is similar except that no datatype is mentioned.  

    Exampl: <code> className::staticVariableName = value; </code>

