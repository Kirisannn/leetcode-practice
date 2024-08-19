#include <iostream>
#include <string>

using namespace std;

class Solution {
   public:
    int minSteps(int n) {
        if (n == 1) return 0;

        int steps = 0;
        int factor = 2;

        while (n > 1) {
            while (n % factor == 0) {
                steps += factor;
                n /= factor;
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