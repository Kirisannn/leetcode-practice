#include <algorithm>
#include <cmath>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
   public:
    int nthUglyNumber(int n) {
        vector<int> dp(n);
        dp[0] = 1;

        int p1 = 0;
        int p2 = 0;
        int p3 = 0;

        for (int i = 1; i < n; i++) {
            int twoMul = dp[p1] * 2;
            int threeMul = dp[p2] * 3;
            int fiveMul = dp[p3] * 5;

            dp[i] = min(twoMul, min(threeMul, fiveMul));

            if (dp[i] == twoMul) {
                p1++;
            }
            if (dp[i] == threeMul) {
                p2++;
            }
            if (dp[i] == fiveMul) {
                p3++;
            }
        }

        return dp[n - 1];
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