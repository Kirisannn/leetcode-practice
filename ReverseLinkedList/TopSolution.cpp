#include <iostream>
#include <vector>

using namespace std;

//  Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
   public:
    // Create a linked list for testing reverseList function
    ListNode *createList(vector<int> values, int valCount) {
        if (valCount == 0) {
            return nullptr;
        }

        ListNode *head = new ListNode(values[0]);
        ListNode *current = head;
        vector<int> newValues = vector(values.begin() + 1, values.end());
        current->next = createList(newValues, valCount - 1);

        return head;
    };

    ListNode *reverseList(ListNode *head) {
        ListNode *pre = nullptr;
        ListNode *cur = head;
        while (cur != nullptr) {
            ListNode *forward = cur->next;
            cur->next = pre;
            pre = cur;
            cur = forward;
        }
        return pre;
    }
};

int main(int argc, char **argv) {
    vector<int> values = {1, 2, 3, 4, 5};
    Solution solution;

    ListNode *head = solution.createList(values, values.size());
    ListNode *temp = head;
    while (temp != nullptr) {
        cout << temp->val << "\t";
        temp = temp->next;
    }
    cout << endl;
    ListNode *reversedHead = solution.reverseList(head);
    while (reversedHead != nullptr) {
        cout << reversedHead->val << "\t";
        reversedHead = reversedHead->next;
    }
    cout << endl;

    return 0;
}