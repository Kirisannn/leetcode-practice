#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res = {0, 0};

        int i = 0, j = 0;
        for (i = 0; i < (int)nums.size(); i++) {
            int diff = target - nums[i];
            for (j = i + 1; j < (int)nums.size(); j++) {
                if (diff == nums[j]) {
                    return {i, j};
                }
            }
        }
        return {0, 0};
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