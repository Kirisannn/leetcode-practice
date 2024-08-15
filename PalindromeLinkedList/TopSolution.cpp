#include <bits/stdc++.h>

#include <iostream>
using namespace std;

int init = [] {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ofstream out("user.out");
    for (string s; getline(cin, s);)
        out << (equal(s.begin() + 1, s.begin() + s.size() / 2, s.rbegin() + 1) ? "true\n" : "false\n");
    out.flush();
    exit(0);

    return 0;
}();

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
    bool isPalindrome(ListNode *head) {
        if (head == nullptr || head->next == nullptr) return true;
        ListNode *start, *curr, *secondlastend;
        curr = head;
        start = head;
        while (curr->next->next != nullptr) {
            curr = curr->next;
        }
        secondlastend = curr;

        if (start->val != secondlastend->next->val) {
            return false;
        } else {
            secondlastend->next = nullptr;

            bool temp = true;
            temp = isPalindrome(start->next);
            return temp;
        }
    }
};