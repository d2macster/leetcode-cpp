//
// Created by Andrii Cherniak on 3/5/18.
//


struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
    void helper(ListNode * node, ListNode * &list, ListNode* &p){
        if (!list)
            list = p = node;
        else {
            p->next = node;
            p = p->next;
        }
    }
public:
    ListNode *partition(ListNode *head, int x) {
        if (!head) return head;
        ListNode * l1 = NULL, * l2 = NULL, *p = head, * p1 = NULL, * p2 = NULL;
        while (p != NULL){
            if (p->val < x) helper(p, l1, p1);
            else helper(p, l2, p2);
            p = p->next;
        }
        if (p1 != NULL) p1->next = NULL;
        if (p2 != NULL) p2->next = NULL;
        if (!l1) return l2;
        if (!l2) return l1;
        p1->next = l2;
        return l1;
    }
};