#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    bool isAnagram(string s, string t) {
        // Base case: If string lengths are unequal -> false
        if (s.length() != t.length()) {
            return false;
        }

        map<char, int> sChars, tChars;
        set<char> hashSetS, hashSetT;
        for (int i = 0; i < (int)s.length(); i++) {
            // If new letter of s, add to hashSet
            if (hashSetS.find(s[i]) == hashSetS.end()) {
                hashSetS.insert(s[i]);
                sChars[s[i]] = 1;
            } else {  // Otherwise, increment char count
                sChars[s[i]]++;
            }

            // If new letter of t, add to hashSet
            if (hashSetT.find(t[i]) == hashSetT.end()) {
                hashSetT.insert(t[i]);
                tChars[t[i]] = 1;
            } else {  // Otherwise, increment char count
                tChars[t[i]]++;
            }
        }

        if (hashSetS.size() != hashSetT.size()) {
            return false;
        }

        auto it = hashSetS.begin(), it2 = hashSetT.begin();
        while (it != hashSetS.end()) {
            if (*it != *it2) {
                return false;
            }
            it++;
            it2++;
        }

        auto it3 = sChars.begin(), it4 = tChars.begin();
        while (it3 != sChars.end()) {
            if (it3->first != it4->first || it3->second != it4->second) {
                return false;
            }

            it3++;
            it4++;
        }

        return true;
    }
};

int main() {
    // Test 1:
    // Input:   s = "anagram", t = "nagaram"
    // Output : true
    {
        Solution sol;
        string s = "anagram", t = "nagaram";
        bool expected = true;
        if (sol.isAnagram(s, t) == expected) {
            cout << "Test 1:\tPassed" << endl;
        } else {
            cout << "Test 1:\tFailed" << endl;
        }
    }

    // Test 2:
    // Input:  s = "rat", t = "car"
    // Output: false
    {
        Solution sol;
        string s = "rat", t = "car";
        bool expected = false;
        if (sol.isAnagram(s, t) == expected) {
            cout << "Test 2:\tPassed" << endl;
        } else {
            cout << "Test 2:\tFailed" << endl;
        }
    }

    return 0;
}