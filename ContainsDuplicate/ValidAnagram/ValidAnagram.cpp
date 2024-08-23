#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

class Solution {
   public:
    bool isAnagram(string s, string t) {
        // Base case: If string lengths are unequal -> false
        if (s.length() != t.length()) {
            return false;
        }

        sort(s.begin(), s.end());
        sort(t.begin(), t.end());

        if (s != t) {
            return false;
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