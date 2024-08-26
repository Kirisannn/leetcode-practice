#include <array>
#include <ios>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

constexpr array<char, 26> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23,
                                    29, 31, 37, 41, 43, 47, 53, 59, 61,
                                    67, 71, 73, 79, 83, 89, 97, 101};

struct Solution {
    inline vector<vector<string>> groupAnagrams(const vector<string>& strs) const {
        unordered_map<double, vector<string>> data(strs.size());
        int i = 0;
        double j;
        while (i < strs.size()) {
            j = 1;
            for (char c : strs[i])
                j *= primes[c - 'a'];
            data.insert({j, vector<string>()})
                .first->second.push_back(strs[i++]);
        }
        vector<vector<string>> output(data.size());
        i = 0;
        for (auto& it : data)
            output[i++].swap(it.second);
        return output;
    }
};

auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();

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