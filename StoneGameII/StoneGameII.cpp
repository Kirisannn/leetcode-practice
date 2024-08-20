#include <climits>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
   protected:
    int maxStones(vector<int>& suffixSum, int m, int currIndex, vector<vector<int>>& dp) {
        if (currIndex + 2 * m >= (int)suffixSum.size()) {
            return suffixSum[currIndex];
        }

        if (dp[currIndex][m] != 0) {
            return dp[currIndex][m];
        }

        int res = INT_MAX;

        for (int i = 1; i <= 2 * m; i++) {
            res = min(res, maxStones(suffixSum, max(i, m), currIndex + i, dp));
        }

        dp[currIndex][m] = suffixSum[currIndex] - res;
        return dp[currIndex][m];
    }

   public:
    int stoneGameII(vector<int>& piles) {
        vector<vector<int>> dp(piles.size(), vector<int>(piles.size()));
        vector<int> suffixSum = piles;  // Copy of piles
        for (int i = piles.size() - 2; i >= 0; i--) {
            suffixSum[i] += suffixSum[i + 1];
        }

        return maxStones(suffixSum, 1, 0, dp);
    }
};

int main() {
    // Test 1: Input - [2, 7, 9, 4, 4], Output - 10
    {
        Solution s;
        vector<int> piles = {2, 7, 9, 4, 4};
        if (s.stoneGameII(piles) == 10) {
            cout << "Test 1 Passed" << endl;
        } else {
            cout << "Test 1 Failed" << endl;
        }
    }

    // Test 2: Input - [1, 2, 3, 4, 5, 100], Output - 104
    {
        Solution s;
        vector<int> piles = {1, 2, 3, 4, 5, 100};
        if (s.stoneGameII(piles) == 104) {
            cout << "Test 2 Passed" << endl;
        } else {
            cout << "Test 2 Failed" << endl;
        }
    }

    return 0;
}