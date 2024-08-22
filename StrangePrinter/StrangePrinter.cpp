#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
   public:
    int strangePrinter(string s) {
        // I want a map, to store the chars, and a vector of all sequences for the char
        // I want a map to store the chars, and a pair of the first and last occurence's index
        unordered_map<char, vector<pair<int, int>>*> charSequences;
        unordered_map<char, pair<int, int>> firstLastOccurence;

        for (int i = 0; i < (int)s.length(); i++) {
            if (charSequences.find(s[i]) == charSequences.end()) {
                charSequences[s[i]] = new vector<pair<int, int>>();
                firstLastOccurence[s[i]] = {i, i};
            }
        }
        char lastC = s[0];
        int startIndex = 0, endIndex = 0;
        for (int i = 1; i < (int)s.length(); i++) {
            if (s[i] != lastC) {
                endIndex = i - 1;
                charSequences[lastC]->push_back({startIndex, endIndex});
                startIndex = i;
                lastC = s[i];
            } else {
                continue;
            }

            if (i == (int)s.length() - 1) {
                charSequences[lastC]->push_back({startIndex, startIndex});
            }
        }

        auto it1 = charSequences.begin();
        auto it2 = firstLastOccurence.begin();

        return 0;
    }
};

int main() {
    // Test 1: Input = "aaabbb", Output = 2
    {
        Solution s;
        string input = "aaabbb";
        int expected = 2;
        if (expected == s.strangePrinter(input)) {
            cout << "Test 1 Passed" << endl;
        } else {
            cout << "Test 1 Failed" << endl;
        }
    }

    // Test 2: Input = "aba", Output = 2
    {
        Solution s;
        string input = "aba";
        int expected = 2;
        if (expected == s.strangePrinter(input)) {
            cout << "Test 2 Passed" << endl;
        } else {
            cout << "Test 2 Failed" << endl;
        }
    }

    // Test 3: Input = "aabbaabbccbbeebb", Output = 5
    {
        Solution s;
        string input = "aabbaabbccbbeebb";
        int expected = 5;
        if (expected == s.strangePrinter(input)) {
            cout << "Test 3 Passed" << endl;
        } else {
            cout << "Test 3 Failed" << endl;
        }
    }

    return 0;
}