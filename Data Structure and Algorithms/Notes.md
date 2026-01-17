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

    -   Fibonacci Series (refer to "fibonacci.cpp" inside "16. Recursion & Problems")
    -   Different ways to climb stairs (refer to "nStairs.cpp" inside "16. Recursion & Problems")
    -   Print the digits' names in a given number (refer to "sayDigits.cpp" inside "16. Recursion & Problems")
    -   Calculate power using recursion (refer to "calculatePower.cpp" inside "16. Recursion & Problems")
    -   Check if a string is Palindrome (refer to "checkPalindrome.cpp" inside "16. Recursion & Problems")
    -   Applied recursive Binary Search (refer to "recursiveBinarySearch.cpp" inside "16. Recursion & Problems")
    -   Applied recursive Bubble Sort (refer to "recursiveBubbleSort.cpp" inside "16. Recursion & Problems")
    -   Applied recursive Insertion Sort (refer to "recursiveInsertionSort.cpp" inside "16. Recursion & Problems")
    -   Applied recursive Linear Search (refer to "recursiveLinearSearch.cpp" inside "16. Recursion & Problems")
    -   Calculate sum of elements in an Array (refer to "sumOfArray.cpp" inside "16. Recursion & Problems")