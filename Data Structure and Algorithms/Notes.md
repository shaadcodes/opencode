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
      - ((a % m) * (b % m)) % m = (a * b) % m  
      - (a / b) % m = (a * (b^-1)) % m

      (refer at: https://codeforces.com/blog/entry/72527)
    
      Fast Exponentiation problem:

      Optimizing exponential calculations for large numbers (in range) using modulo  
      (refer to "fastExponentiation.cpp" inside "Mathematics for DSA")
