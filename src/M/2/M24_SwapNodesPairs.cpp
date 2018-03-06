//
// Created by Andrii Cherniak on 3/6/18.
//


struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *swapPairs(ListNode *head) {
        if (!head || !head->next) return head;
        ListNode * p, *next2, *next, *next3;
        ListNode * new_head = new ListNode(0);
        new_head->next = head;
        p = new_head;
        while (p->next && p->next->next){
            next = p->next;
            next2 = next->next;
            next3 = next2->next;
            p->next = next2;
            next2->next = next;
            next->next = next3;
            p = next;
        }

        return new_head->next;
    }
};