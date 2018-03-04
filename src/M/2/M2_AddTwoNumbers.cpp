//
// Created by Andrii Cherniak on 3/3/18.
//


struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        int bit = 0;
        if (!l1)
            return l2;
        if (!l2)
            return l1;
        ListNode *begin = NULL, *p, *p_prev = NULL;
        while (l1 != NULL || l2 != NULL) {
            p = new ListNode(0);
            if (p_prev != NULL) p_prev->next = p;
            if (l1 != NULL){
                p->val += l1->val;
                l1 = l1->next;
            }
            if (l2 != NULL){
                p->val += l2->val;
                l2 = l2->next;
            }

            p->val += bit;
            bit = p->val / 10;
            p->val %= 10;
            if (!begin) begin = p;
            p_prev = p;
        }
        if (bit != 0) {
            p = new ListNode(bit);
            p_prev->next = p;
        }

        return begin;
    }
};