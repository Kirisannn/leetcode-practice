#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        int n = (int)strs.size();
        vector<bool> isGrouped(n);
        vector<string> strCpy = strs;

        for (int i = 0; i < n; i++) {
            if (isGrouped[i] == true) {
                continue;
            }
            isGrouped[i] = true;
            vector<string> group;
            group.push_back(strs[i]);
            sort(strCpy[i].begin(), strCpy[i].end());
            for (int j = i + 1; j < n; j++) {
                if (isGrouped[j] == true) {
                    continue;
                }
                sort(strCpy[j].begin(), strCpy[j].end());
                if (strCpy[i] == strCpy[j]) {
                    isGrouped[j] = true;
                    group.push_back(strs[j]);
                }
            }
            res.push_back(group);
        }
        return res;
    }
};

int main() {
    // Test 1
    // Input: strs = [ "eat", "tea", "tan", "ate", "nat", "bat" ]
    // Output : [ ["bat"], [ "nat", "tan" ], [ "ate", "eat", "tea" ] ]
    {
        Solution s;
        vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
        vector<vector<string>> expected = {{"bat"}, {"nat", "tan"}, {"ate", "eat", "tea"}};
        s.groupAnagrams(strs);
    }
    return 0;
}