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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (!headA || !headB) return NULL;
        ListNode *pA = headA, *pB = headB;
        while (pA != pB){
            pA = (pA != NULL)?pA->next:headB;
            pB = (pB != NULL)?pB->next:headA;
        }
        return pA;
    }
};