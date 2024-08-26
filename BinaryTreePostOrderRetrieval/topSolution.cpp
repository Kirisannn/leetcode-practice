#include <algorithm>
#include <cassert>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

//  Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
   public:
    // Construct a binary tree from a vector
    TreeNode *constructTree(vector<int> &input) {
        if (input.empty()) {
            return nullptr;
            ;
        }
        TreeNode *root = new TreeNode(input[0]);
        vector<TreeNode *> nodes = {root};
        for (int i = 1; i < (int)input.size(); i++) {
            if (input[i] != NULL) {
                TreeNode *node = new TreeNode(input[i]);
                nodes.push_back(node);
                if (i % 2 == 1) {
                    nodes[(i - 1) / 2]->left = node;
                } else {
                    nodes[(i - 1) / 2]->right = node;
                }
            }
        }
        return root;
    }

    vector<int> postorderTraversal(TreeNode *root) {
        if (root == NULL) return {};
        stack<TreeNode *> st;
        st.push(root);
        vector<int> ans;
        while (!st.empty()) {
            TreeNode *top = st.top();
            st.pop();
            ans.push_back(top->val);
            if (top->left) st.push(top->left);    // push left element
            if (top->right) st.push(top->right);  // push right element
        }
        reverse(ans.begin(), ans.end());  // reverse for post order
        return ans;
    }
};

int main() {
    // Test 1: input = {1, null, 2, 3}, output = {3, 2, 1}
    Solution s;
    vector<int> input = {1, NULL, 2, 3, 4}, expected = {3, 4, 2, 1};
    TreeNode *root = s.constructTree(input);
    vector<int> output = s.postorderTraversal(root);
    assert(output == expected);

    // Test 2: input = {}, output = {}
    input = {};
    expected = {};
    root = s.constructTree(input);
    output = s.postorderTraversal(root);
    assert(output == expected);

    // Test 3: input = {1}, output = {1}
    input = {1};
    expected = {1};
    root = s.constructTree(input);
    output = s.postorderTraversal(root);
    assert(output == expected);

    return 0;
}