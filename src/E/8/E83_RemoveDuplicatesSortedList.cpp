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
    ListNode *deleteDuplicates(ListNode *head) {
        if (!head)
            return head;
        ListNode *p1, *p2;
        p1 = head;
        p2 = head->next;
        while (p2 != NULL){
            p1->next = p2;
            if (p1->val != p2->val) p1 = p2;
            p2 = p2->next;
        }
        p1->next = p2;
        return head;
    }
};