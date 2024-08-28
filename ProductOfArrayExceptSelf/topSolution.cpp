#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> prod_Arr(n, 1);
        int left_Prod = 1;
        for (int i = 0; i < n; ++i) {
            prod_Arr[i] *= left_Prod;
            left_Prod *= nums[i];
        }
        int right_Prod = 1;
        for (int i = n - 1; i >= 0; --i) {
            prod_Arr[i] *= right_Prod;
            right_Prod *= nums[i];
        }
        return prod_Arr;
    }
};

auto init = []() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();

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