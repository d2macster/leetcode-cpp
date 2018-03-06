//
// Created by Andrii Cherniak on 3/5/18.
//


struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
    void helper(ListNode *n) {
        if (!n->next) n->val += 1;
        else {
            helper(n->next);
            if (n->next->val > 9) {
                n->next->val %= 10;
                n->val++;
            }
        }
    }

public:
    ListNode *plusOne(ListNode *head) {
        helper(head);
        if (head->val > 9){
            head->val %= 10;
            ListNode * n = new ListNode(1);
            n->next = head;
            return n;
        } else return head;
    }
};