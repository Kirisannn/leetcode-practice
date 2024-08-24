#include <iostream>
#include <string>

using namespace std;

class Solution {
   public:
    bool isAnagram(string s, string t) {
        int hash1[26];
        int hash2[26];
        if (s.size() != t.size()) {
            return false;
        }

        for (int i = 0; i < s.size(); i++) {
            hash1[s[i] - 'a']++;
            hash2[t[i] - 'a']++;
        }

        for (int i = 0; i < 26; i++) {
            if (hash1[i] != hash2[i]) {
                return false;
            }
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