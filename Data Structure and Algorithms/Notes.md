### 17th December 2025
**LEARNED ABOUT MATHEMATICAL CONCEPTS FOR DATA STRUCTURES AND ALGORITHMS**

Topics Covered
  - **Sieve of Eratosthenes**

      Sieve of Eratosthenes is a technique used to eliminate or **sieve - out** the number of comparisons performed by CPU,
      which can be useful to significantly reduce the CPU time for an algorithm.
    
      Created a C++ program to count prime numbers till 'n' using Sieve of Eratosthenes Technique (refer to "sieveOfEratosthenes.cpp" inside "Mathematics for DSA")

  - **Segmented Sieve**

      Segmented sieve technique is polished version of Eratosthenes Sieve technique, optimized for large datasets, which are not possible to compute with Simple Sieve
      (refer at: https://www.geeksforgeeks.org/dsa/segmented-sieve/)

  - **GCD (Greatest Common Divisor) / HCF (Highest Common Factor)**

      - Euclid's Theorem: GCD(a, b) = GCD(a-b, b)
        
        Code of Euclid's Theorem (refer to "euclidsGCD.cpp" inside "Mathematics for DSA")

        Conceptual in-depth understanding of GCD in Computer Science (refer at: https://www.geeksforgeeks.org/dsa/euclidean-algorithms-basic-and-extended/)
        
  - **Modular Arithmetics**
    
      Basics of Modular Arithmetics:

      ((a % m) + (b % m)) % m = (a + b) % m
    
      ((a % m) - (b % m)) % m = (a - b) % m
    
      ((a % m) * (b % m)) % m = (a * b) % m
    
      (a / b) % m = (a * (b^-1)) % m

      LCM(a, b) * GCD(a, b) = a * b

      (refer at: https://codeforces.com/blog/entry/72527)
    
      - Fast Exponentiation problem:

        Optimizing exponential calculations for large numbers using modulo
        
        (refer to "fastExponentiation.cpp" inside "Mathematics for DSA")
