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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        if (!head || n <= 0)
            return head;
        ListNode *p = head, *pn = NULL;
        int counter = 0;
        while (p != NULL) {
            p = p->next;
            if (pn != NULL) pn = pn->next;
            if (counter == n) pn = head;
            counter++;
        }
        if (pn != NULL) pn->next = pn->next->next;
        else return head->next;
        return head;
    }
};