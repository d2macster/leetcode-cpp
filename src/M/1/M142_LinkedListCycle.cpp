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
    ListNode *detectCycle(ListNode *head) {
        if (!head || !head->next) return NULL;
        ListNode *p1 = head, *p2 = head;
        while (p2 != NULL){
            p1 = p1->next;
            if (!p2->next)
                return NULL;
            p2 = p2->next->next;
            if (p1 == p2) break;
        }
        if (!p2) return NULL;
        p1 = head;
        while (p1 != p2){
            p1 = p1->next;
            p2 = p2->next;
        }
        return p1;
    }
};