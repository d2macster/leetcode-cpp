//
// Created by Andrii Cherniak on 3/5/18.
//
#include <stack>

using std::stack;

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode *sum = NULL, *node;
        stack<int> s1, s2;
        while (l1 != NULL) {
            s1.push(l1->val);
            l1 = l1->next;
        }
        while (l2 != NULL) {
            s2.push(l2->val);
            l2 = l2->next;
        }
        int overflow = 0, v, v1, v2;
        while (!s1.empty() || !s2.empty() || overflow > 0) {
            v1 = s1.empty() ? 0 : s1.top();
            v2 = s2.empty() ? 0 : s2.top();
            if (!s1.empty())s1.pop();
            if (!s2.empty()) s2.pop();
            v = v1 + v2 + overflow;

            overflow = v / 10;
            v %= 10;
            node = new ListNode(v);
            node->next = sum;
            sum = node;
        }

        return sum;
    }
};