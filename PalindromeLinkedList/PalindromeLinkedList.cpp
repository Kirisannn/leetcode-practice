#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

// Definition for singly-linked list.
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

    bool isPalindrome(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return true;
        }

        int count = 0;
        ListNode* temp = head;
        while (temp != nullptr) {
            count++;
            temp = temp->next;
        }

        int mid = count / 2;
        ListNode* curr = head;
        ListNode* prev = nullptr;
        ListNode* next = nullptr;
        // Change direction of nodes from beginning to halfway
        for (int i = 0; i < mid; i++) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        if (count % 2 == 1) {
            next = next->next;
        }

        for (int i = 0; i < mid; i++) {
            if (prev->val != next->val) {
                return false;
            }
            prev = prev->next;
            next = next->next;
        }

        return true;
    }
};

int main() {
    vector<int> values = {1, 2, 3, 3, 2, 1};
    Solution solution;

    ListNode* head = solution.createList(values, values.size());
    ListNode* temp = head;
    while (temp != nullptr) {
        cout << temp->val << "\t";
        temp = temp->next;
    }
    cout << endl;
    if (solution.isPalindrome(head) == true) {
        cout << "True" << endl;
    } else {
        cout << "False" << endl;
    }
    return 0;
}