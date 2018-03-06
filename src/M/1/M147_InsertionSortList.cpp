//
// Created by Andrii Cherniak on 3/5/18.
//

#include <iostream>


struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *insertionSortList(ListNode *head) {
        if (!head) return head;
        ListNode *new_head = new ListNode(0);
        new_head->next = head;
        ListNode *p = new_head->next;
        ListNode *p_prev = new_head->next;
        ListNode *p_next, *p_insert;

        while (p != NULL) {
            if (p->next && p->next->val < p->val) {
                p_next = p->next;
                p->next = p_next->next;
                p_prev = new_head;
                while (p_prev->next->val < p_next->val) p_prev = p_prev->next;
                p_next->next = p_prev->next;
                p_prev->next = p_next;
            } else p = p->next;
        }

        return new_head->next;
    }
};