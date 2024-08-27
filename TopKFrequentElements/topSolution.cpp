#include <algorithm>
#include <cassert>
#include <iostream>
#include <map>
#include <set>
#include <vector>

using namespace std;

class Solution {
   public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> result;
        map<int, set<int>> freq;  // first->frequency, second->val
        sort(nums.begin(), nums.end());
        int start = 0, currVal = nums[0], count;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != currVal) {
                count = i - start;
                freq[count].insert(currVal);
                start = i;
                currVal = nums[i];
            }

            if (i == nums.size() - 1) {
                count = i - start + 1;
                freq[count].insert(currVal);
            }
        }

        for (auto it = freq.rbegin(); it != freq.rend(); it++) {
            for (auto val : it->second) {
                result.push_back(val);
                if (result.size() == k) {
                    break;
                }
            }

            if (result.size() == k) {
                break;
            }
        }

        return result;
    }
};

int main() {
    Solution s;
    // Test 1: input = {1,1,1,2,2,3}, k = 2, expected = {1,2}
    int k = 2;
    vector<int> nums = {1, 1, 1, 2, 2, 3}, expected = {1, 2}, output = s.topKFrequent(nums, k);
    assert(expected == output);

    // Test 2: input = {1}, k = 1, expected = {1}
    k = 1;
    nums = {1}, expected = {1}, output = s.topKFrequent(nums, k);
    assert(expected == output);

    return 0;
}