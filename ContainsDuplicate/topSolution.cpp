#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    bool containsDuplicate(vector<int>& nums) {
    }
};

int main() {
    // Test 1: Input - [1,2,3,1], Output - true
    {
        Solution s;
        vector<int> input = {1, 2, 3, 1};
        bool expected = true;
        if (s.containsDuplicate(input) == expected) {
            cout << "Test 1:\tPassed" << endl;
        } else {
            cout << "Test 1:\tFailed" << endl;
        }
    }

    // Test 2: Input - [1,2,3,4], Output - false
    {
        Solution s;
        vector<int> input = {1, 2, 3, 4};
        bool expected = false;
        if (s.containsDuplicate(input) == expected) {
            cout << "Test 2:\tPassed" << endl;
        } else {
            cout << "Test 2:\tFailed" << endl;
        }
    }

    // Test 3: Input - [1,1,1,3,3,4,3,2,4,2], Output - true
    {
        Solution s;
        vector<int> input = {1, 1, 1, 3, 3, 4, 3, 2, 4, 2};
        bool expected = true;
        if (s.containsDuplicate(input) == expected) {
            cout << "Test 3:\tPassed" << endl;
        } else {
            cout << "Test 3:\tFailed" << endl;
        }
    }
    return 0;
}
