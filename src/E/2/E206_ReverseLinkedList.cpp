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
    ListNode *reverseList(ListNode *head) {
        if (!head) return head;
        ListNode *new_head = NULL, * p_prev = NULL, * p = head, *p_next;
        while (p != NULL){
            p_next = p->next;
            p->next = p_prev;
            p_prev = p;
            new_head = p;
            p = p_next;
        }
        return new_head;
    }
};