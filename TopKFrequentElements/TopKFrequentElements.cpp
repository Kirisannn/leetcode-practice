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
        vector<int> result(k);
        map<int, int> freq;
        vector<pair<int, int>> freqReverse;
        for (int num : nums) {
            freq[num]++;
        }

        for (auto it = freq.begin(); it != freq.end(); it++) {
            freqReverse.push_back({it->second, it->first});
        }

        sort(freqReverse.begin(), freqReverse.end(), greater<pair<int, int>>());

        for (int i = 0; i < k; i++) {
            result[i] = freqReverse[i].second;
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