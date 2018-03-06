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
    ListNode *oddEvenList(ListNode *head) {
        if (!head) return head;
        ListNode * odd = NULL, *even = NULL, *p = head, *p_next, *even_begins = NULL;
        int L = 0;

        while (p != NULL){
            p_next = p->next;
            L++;
            if (L % 2 == 1){
                if (!odd) odd = p;
                else {
                    odd->next = p;
                    odd = p;
                }
            } else{
                if (!even)
                    even_begins = even = p;
                else{
                    even->next = p;
                    even = p;
                }
            }
            p->next = NULL;
            p = p_next;
        }
        if (odd != NULL) odd->next = even_begins;
        return head;
    }
};