#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int, int>> nNums(nums.size(), {0, 0});
        for (int i = 0; i < nums.size(); ++i) {
            nNums[i] = {nums[i], i};
        }
        sort(nNums.begin(), nNums.end());
        int l = 0;
        int r = nNums.size() - 1;
        while (l < r) {
            if (nNums[l].first + nNums[r].first == target) return vector<int>{nNums[l].second, nNums[r].second};

            if (nNums[l].first + nNums[r].first < target)
                ++l;
            else
                --r;
        }
        return vector<int>{nNums[l].second, nNums[r].second};
    }
};

int main() {
    // Test 1:
    {
        Solution s;
        vector<int> nums = {2, 7, 11, 15}, expected = {0, 1};
        int target = 9;
        if (s.twoSum(nums, target) == expected) {
            cout << "Test 1:\tPassed" << endl;
        } else {
            cout << "Test 1:\tFailed" << endl;
        }
    }

    // Test 2:
    {
        Solution s;
        vector<int> nums = {3, 2, 4}, expected = {1, 2};
        int target = 6;
        if (s.twoSum(nums, target) == expected) {
            cout << "Test 2:\tPassed" << endl;
        } else {
            cout << "Test 2:\tFailed" << endl;
        }
    }
    return 0;
}