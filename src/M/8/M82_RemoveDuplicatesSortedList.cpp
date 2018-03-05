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
    ListNode *deleteDuplicates(ListNode *head) {
        if (!head) return head;
        ListNode * p = head->next, * new_head = NULL, *p_prev = head, *last = NULL;
        int cnt = 1;
        while (p != NULL){
            if (p_prev->val != p->val){
                if (cnt == 1){
                    if (!last){
                        new_head = last = p_prev;
                    }else{
                        last->next = p_prev;
                        last = p_prev;
                    }
                }
                p_prev = p;
                cnt = 1;
            } else cnt++;
            p = p->next;
        }
        if (cnt == 1){
            if (!last){
                new_head = last = p_prev;
            }else{
                last->next = p_prev;
                last = p_prev;
            }
        }
        if (last != NULL) last->next = NULL;
        return new_head;
    }
};