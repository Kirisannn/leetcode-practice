#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> prefixProduct, postfixProduct, result;

        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (i != 0) {
                prefixProduct.push_back(prefixProduct.back() * nums[i]);
            } else {
                prefixProduct.push_back(nums[i]);
            }
        }

        for (int i = n - 1; i >= 0; i--) {
            if (i != n - 1) {
                postfixProduct.push_back(postfixProduct.back() * nums[i]);
            } else {
                postfixProduct.push_back(nums[i]);
            }
        }

        for (int i = 0; i < n; i++) {
            if (i == 0) {
                result.push_back(postfixProduct[n - 2]);
            } else if (i == n - 1) {
                result.push_back(prefixProduct[n - 2]);
            } else {
                result.push_back(prefixProduct[i - 1] * postfixProduct[n - i - 2]);
            }
        }

        return result;
    }
};

int main() {
    Solution s;
    // Test 1
    vector<int> nums = {1, 2, 3, 4},
                expected = {24, 12, 8, 6},
                output = s.productExceptSelf(nums);
    cout << "Test 1:\t" << (output == expected ? "Passed" : "Failed") << endl;

    // Test 2
    nums = {-1, 1, 0, -3, 3};
    expected = {0, 0, 9, 0, 0};
    output = s.productExceptSelf(nums);
    cout << "Test 2:\t" << (output == expected ? "Passed" : "Failed") << endl;
}