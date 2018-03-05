//
// Created by Andrii Cherniak on 3/5/18.
//


struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        if (!head || m < 1 || n < 1 || m > n) return head;
        ListNode * new_head = new ListNode(0);
        new_head->next = head;
        ListNode * p1 = new_head;
        for (int i = 1; i < m; i++) p1 = p1->next;
        ListNode * p2 = p1->next, *p1_end = p1, *p2_next, *p2_prev = NULL, *p2_end = NULL;
        for (int i = m; i <= n; i++) {
            if (!p2_end) p2_end = p2;
            p2_next = p2->next;
            p2->next = p2_prev;
            p2_prev = p2;
            p2 = p2_next;
        }
        p1_end->next = p2_prev;
        p2_end->next = p2;

        return new_head->next;
    }
};