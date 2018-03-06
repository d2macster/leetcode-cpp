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
    void reorderList(ListNode *head) {
        if (!head || !head->next || !head->next->next) return;
        ListNode *p1 = head, *p2 = head->next;
        // split
        while (p2 && p2->next) {
            p1 = p1->next;
            p2 = p2->next->next;
        }
        ListNode * next_head, * result;
        p2 = p1->next;
        p1->next = NULL;
        ListNode * next, * prev = NULL;

        //reverse
        while (p2){
            next_head = p2;
            next = p2->next;
            p2->next = prev;
            prev = p2;
            p2 = next;

        }

        //merge
        p1 = head;
        p2 = next_head;
        while (p1 && p2){
            next = p1->next;
            p1->next = p2;
            p1 = next;
            next = p2->next;
            p2->next = p1;
            p2 = next;
        }
    }
};