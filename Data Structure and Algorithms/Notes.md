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

Changes in "Data Stuctures And Algorithms" - **1 - 13 Folders** - Introduction to Programming - Conditional Statements and Loops - Patterns - Bitwise Operators, Number Systems and Probability - Switch Statements and Functions - Arrays in C++ and Problems - Binary Search and Problems - Sorting Techniques - Standard C++ Template Library - Character Arrays & Strings - 2 Dimensional Arrays - Mathematics for DSA - Pointers in C++

### 23rd December 2025

**POINTERS IN C++**

Topics 

- **What?**

    Pointers are variables which store **memory addresses** of other variables
    Size of a pointer is 8 bytes, independant of the type of variable it points to

- **How?**

    Pointers of any specific type can be created using the syntax:
        __type *pointer__
    Example:
        int *p = &n;
        & -> Address of operator
        (this will be read as, "p is a pointer to integer n" or "address of n is stored in p")

- **Why?**

    Pointers are useful to directly work with values by modifying using addresses in functions rather than using
    copy of variables passed
    Pointers are useful in memory management

- **Pointers with Arrays**

    When a pointer to an array is created, the pointer stores the address of the first element of array
    for a pointer p and an array,
    such that: *p = array[0] = array;
