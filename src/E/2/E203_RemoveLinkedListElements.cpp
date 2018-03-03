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
    ListNode *removeElements(ListNode *head, int val) {
        if (!head) return head;
        ListNode *new_head = NULL, *ptr = NULL, *p = head;
        while (p != NULL) {
            if (p->val != val) {
                if (!new_head)
                    new_head = ptr = p;
                else {
                    ptr->next = p;
                    ptr = p;
                }
            }
            p = p->next;
        }
        if (ptr != NULL) ptr->next = NULL;

        return new_head;

    }
};