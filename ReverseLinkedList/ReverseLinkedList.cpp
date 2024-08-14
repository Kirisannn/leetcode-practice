// Leetcode daily
// No. 206 - Reverse Linked List (Easy)

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

//  Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
   public:
    // Create a linked list for testing reverseList function
    ListNode* createList(vector<int> values, int valCount) {
        if (valCount == 0) {
            return nullptr;
        }

        ListNode* head = new ListNode(values[0]);
        ListNode* current = head;
        vector<int> newValues = vector(values.begin() + 1, values.end());
        current->next = createList(newValues, valCount - 1);

        return head;
    };

    ListNode* reverseList(ListNode* head) {
        if (head == nullptr) {
            return nullptr;
        }
        vector<ListNode*> nodes;
        nodes.push_back(head);

        while (head->next != nullptr) {
            head = head->next;
            nodes.push_back(head);
        }
        reverse(nodes.begin(), nodes.end());
        head = nodes[0];
        for (int i = 0; i < (int)nodes.size() - 1; i++) {
            nodes[i]->next = nodes[i + 1];
        }
        nodes[nodes.size() - 1]->next = nullptr;

        return nodes[0];
    }
};

int main(int argc, char** argv) {
    vector<int> values = {1, 2, 3, 4, 5};
    Solution solution;

    ListNode* head = solution.createList(values, values.size());
    ListNode* temp = head;
    while (temp != nullptr) {
        cout << temp->val << "\t";
        temp = temp->next;
    }
    cout << endl;
    ListNode* reversedHead = solution.reverseList(head);
    while (reversedHead != nullptr) {
        cout << reversedHead->val << "\t";
        reversedHead = reversedHead->next;
    }
    cout << endl;

    return 0;
}