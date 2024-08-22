#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    int strangePrinter(string s) {
        // Preprocess the string to remove consecutive duplicate characters
        s = removeDuplicates(s);
        int n = s.length();
        // Initialize memoization array
        vector<vector<int>> memo(n, vector<int>(n, -1));
        // Start the recursive process
        return minimumTurns(0, n - 1, s, memo);
    }

   private:
    int minimumTurns(int start, int end, string& s, vector<vector<int>>& memo) {
        // Base case: empty string requires 0 turns
        if (start > end) {
            return 0;
        }

        // If result is memoized, return it
        if (memo[start][end] != -1) {
            return memo[start][end];
        }

        // Initialize with worst case: print each character separately
        int minTurns = 1 + minimumTurns(start + 1, end, s, memo);

        // Try to optimize by finding matching characters
        for (int k = start + 1; k <= end; k++) {
            if (s[k] == s[start]) {
                // If match found, try splitting the problem
                int turnsWithMatch = minimumTurns(start, k - 1, s, memo) +
                                     minimumTurns(k + 1, end, s, memo);
                minTurns = min(minTurns, turnsWithMatch);
            }
        }

        // Memoize and return the result
        return memo[start][end] = minTurns;
    }

    string removeDuplicates(string& s) {
        string uniqueChars;
        int i = 0;
        while (i < (int)s.length()) {
            char currentChar = s[i];
            uniqueChars += currentChar;
            // Skip all consecutive occurrences of the current character
            while (i < (int)s.length() && s[i] == currentChar) {
                i++;
            }
        }
        return uniqueChars;
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