#include <cassert>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

// Definition for a Node.
struct Node {
    int val;
    vector<Node*> children;
    Node() {}
    Node(int _val) {
        val = _val;
    }
    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
   public:
    Node* createTree(vector<int>& values) {
        Node* root;

        if (values.size() == 0) {
            return root;
        }

        root = new Node(values[0]);
        queue<Node*> nodes;
        nodes.push(root);
        Node* currParent;

        for (int i = 1; i < values.size(); i++) {
            if (values[i] == NULL) {
                currParent = nodes.front();
                nodes.pop();
                continue;
            }

            Node* newNode = new Node(values[i]);
            nodes.push(newNode);
            currParent->children.push_back(newNode);
        }

        return root;
    }

    void trav(Node* at, vector<int>& res) {
        if (at == nullptr)
            return;
        for (auto k : at->children)
            trav(k, res);
        res.push_back(at->val);
    }
    vector<int> postorder(Node* root) {
        vector<int> res;
        trav(root, res);
        return res;
    }
};

int main() {
    Solution sol;
    // Test 1
    vector<int> values = {1, NULL, 3, 2, 4, NULL, 5, 6},
                expected = {5, 6, 3, 2, 4, 1};
    Node* root = sol.createTree(values);
    vector<int> result = sol.postorder(root);
    // cout << "Test 1:\t" << endl;
    // assert(result == expected);
    // cout << "Passed" << endl;

    // Test 2
    values = {1, NULL, 2, 3, 4, 5, NULL, NULL, 6, 7, NULL, 8, NULL, 9, 10, NULL, NULL, 11, NULL, 12, NULL, 13, NULL, NULL, 14};
    expected = {2, 6, 14, 11, 7, 3, 12, 8, 4, 13, 9, 10, 5, 1};
    root = sol.createTree(values);
    result = sol.postorder(root);
    // cout << "Test 2:\t" << endl;
    // assert(result == expected);
    // cout << "Passed" << endl;

    return 0;
}