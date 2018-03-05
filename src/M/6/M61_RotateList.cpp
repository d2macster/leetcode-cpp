//
// Created by Andrii Cherniak on 3/4/18.
//


struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *rotateRight(ListNode *head, int k) {
        if (!head || k <= 0) return head;
        ListNode *p = head, *new_head = NULL;
        int L = 1, c = 1;
        while (p->next != NULL) {
            L++;
            p = p->next;
        }
        k %= L;
        if (k == 0) return head;
        p->next = head;
        p = head;
        while (c < (L - k)){
            p = p->next;
            c++;
        }
        new_head = p->next;
        p->next = NULL;
        return new_head;
    }
};