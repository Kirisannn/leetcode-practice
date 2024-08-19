#include <iostream>
#include <string>

using namespace std;

class Solution {
   protected:
    // Square Root Optimized Trial Division Approach:
    // https://www.geeksforgeeks.org/c-program-to-check-prime-number/
    bool isPrime(int N) {
        // If the number is less than or equal to 1,
        // it is not prime
        if (N <= 1) {
            return false;
        }

        // If the number is 2 or 3, it is prime
        if (N <= 3) {
            return true;
        }

        // If the number is divisible by 2 or 3,
        // it is not prime
        if (N % 2 == 0 || N % 3 == 0) {
            return false;
        }

        // Check for divisors from 5
        // to the square root of N
        for (int i = 5; i * i <= N; i += 6) {
            // If N is divisible by i or (i + 2),
            // it is not prime
            if (N % i == 0 || N % (i + 2) == 0) {
                return false;
            }
        }

        // If no divisors are found, it is prime
        return true;
    }

   public:
    int minSteps(int n) {
        // Base case: n = 1
        if (n == 1) {
            return 0;
        }

        // Base Case: n is a prime number
        if (isPrime(n) || n == 2 || n == 3 || n == 4 || n == 5) {
            return n;
        }

        // Otherwise, for 1 < n <= 1000, minimally will require 1 operation
        int steps = 0;
        int factor = 2;  // Minimum factor

        while (n > 1) {
            while (n % factor == 0) {
                n /= factor;
                steps += factor;
            }
            factor++;
        }
        return steps;
    }
};

int main() {
    // Test 1: Expected 5
    {
        Solution solution;
        int n = 6;
        int expected = 5;
        if (solution.minSteps(n) == expected) {
            cout << "Test 1 Passed" << endl;
        } else {
            cout << "Test 1 Failed" << endl;
        }
    }

    // Test 2: Expected 6
    {
        Solution solution;
        int n = 8;
        int expected = 6;
        if (solution.minSteps(n) == expected) {
            cout << "Test 2 Passed" << endl;
        } else {
            cout << "Test 2 Failed" << endl;
        }
    }

    // Test 3: Expected 6
    {
        Solution solution;
        int n = 9;
        int expected = 6;
        if (solution.minSteps(n) == expected) {
            cout << "Test 3 Passed" << endl;
        } else {
            cout << "Test 3 Failed" << endl;
        }
    }

    // Test 4: Expected 7
    {
        Solution solution;
        int n = 10;
        int expected = 7;
        if (solution.minSteps(n) == expected) {
            cout << "Test 4 Passed" << endl;
        } else {
            cout << "Test 4 Failed" << endl;
        }
    }

    // Test 5: Expected 7
    {
        Solution solution;
        int n = 12;
        int expected = 7;
        if (solution.minSteps(n) == expected) {
            cout << "Test 5 Passed" << endl;
        } else {
            cout << "Test 5 Failed" << endl;
        }
    }

    // Test 6: Expected 9
    {
        Solution solution;
        int n = 14;
        int expected = 9;
        if (solution.minSteps(n) == expected) {
            cout << "Test 6 Passed" << endl;
        } else {
            cout << "Test 6 Failed" << endl;
        }
    }

    return 0;
}