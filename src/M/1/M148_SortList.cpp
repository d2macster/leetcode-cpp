//
// Created by Andrii Cherniak on 3/5/18.
//

#include <iostream>

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        if (!l1) return l2;
        if (!l2) return l1;
        if (l1->val <= l2->val){
            ListNode * m = mergeTwoLists(l1->next, l2);
            l1->next = m;
            return l1;
        } else{
            ListNode * m = mergeTwoLists(l1, l2->next);
            l2->next = m;
            return l2;
        }
    }
    ListNode * sort(ListNode * n){
        if (!n || !n->next) return n;
        ListNode * p1 = n, * p2 = n->next;
        p1 = n;
        while (p2 && p2->next != NULL){
            p1 = p1->next;
            p2 = p2->next->next;
        }
        p2 = p1->next;
        p1->next = NULL;
        ListNode * l1 = sort(n);
        ListNode * l2 = sort(p2);
        return mergeTwoLists(l1, l2);
    }
public:
    ListNode *sortList(ListNode *head) {
        if (!head || !head->next) return head;
        return sort(head);
    }
};