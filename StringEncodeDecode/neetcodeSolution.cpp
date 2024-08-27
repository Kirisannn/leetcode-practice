#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    string encode(vector<string>& strs) {
        string result = "";

        for (int i = 0; i < (int)strs.size(); i++) {
            string str = strs[i];
            result += to_string(str.size()) + "#" + str;
        }

        return result;
    }

    vector<string> decode(string s) {
        vector<string> result;

        int i = 0;
        while (i < (int)s.size()) {
            int j = i;
            while (s[j] != '#') {
                j++;
            }
            int length = stoi(s.substr(i, j - i));
            string str = s.substr(j + 1, length);
            result.push_back(str);
            i = j + 1 + length;
        }

        return result;
    }
};

int main() {
    Solution sol;

    // Test 1
    vector<string> strs = {"neet", "code", "love", "you"}, expected = strs;
    string s = sol.encode(strs);
    vector<string> actual = sol.decode(s);
    cout << "Test 1:\t";
    assert(expected == actual);
    cout << "Passed" << endl;

    // Test 2
    strs = {"we", "say", ":", "yes"};
    expected = strs;
    s = sol.encode(strs);
    actual = sol.decode(s);
    cout << "Test 2:\t";
    assert(expected == actual);
    cout << "Passed" << endl;

    // Test 3
    strs = {"we", "say", ":", "yes", "!@#$%^&*()"};
    expected = strs;
    s = sol.encode(strs);
    actual = sol.decode(s);
    cout << "Test 3:\t";
    assert(expected == actual);
    cout << "Passed" << endl;

    return 0;
}