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
};