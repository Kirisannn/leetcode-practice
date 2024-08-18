#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
   public:
    int nthUglyNumber(int n) {
        int two = 0, three = 0, five = 0, res = 0;

        vector<int> dp(n);
        dp[0] = 1;
        return res;
    }
};

int main() {
    // Test 1
    {
        Solution s;
        int n = 10, expected = 12;
        if (s.nthUglyNumber(n) == expected) {
            cout << "Test 1 Passed" << endl;
        } else {
            cout << "Test 1 Failed" << endl;
        }
    }

    // Test 2
    {
        Solution s;
        int n = 1, expected = 1;
        if (s.nthUglyNumber(n) == expected) {
            cout << "Test 2 Passed" << endl;
        } else {
            cout << "Test 2 Failed" << endl;
        }
    }

    // // Test 3
    // {
    //     Solution s;
    //     int n = 10, expected = 12;
    //     if (s.nthUglyNumber(n) == expected) {
    //         cout << "Test 3 Passed" << endl;
    //     } else {
    //         cout << "Test 3 Failed" << endl;
    //     }
    // }

    return 0;
}