#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    string encode(vector<string>& strs) {
        string res = "";

        for (int i = 0; i < (int)strs.size(); i++) {
            res += to_string(strs[i].length()) + "#" + strs[i];
        }

        return res;
    }

    vector<string> decode(string s) {
        vector<string> res;

        if (s.length() > 0) {
            int wordCount = count(s.begin(), s.end(), '#'),
                pound = s.find('#'),
                charCount = stoi(s.substr(0, pound));
            string str = "";
            for (int i = 0; i < wordCount; i++) {
                str = s.substr(pound + 1, charCount);
                res.push_back(str);
                s = s.substr(pound + charCount + 1);
                if (i != wordCount - 1) {
                    pound = s.find('#');
                    if (pound == -1) {
                        break;
                    }
                    charCount = stoi(s.substr(0, pound));
                }
            }
        }

        return res;
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