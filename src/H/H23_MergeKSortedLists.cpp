//
// Created by Andrii Cherniak on 4/6/18.
//

#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
    ListNode *mergeTwo(ListNode *l1, ListNode *l2) {
        ListNode *head = NULL;
        ListNode *tail = NULL;
        ListNode *next;
        while (l1 != NULL || l2 != NULL){
            if (l1 == NULL) {
                next = l2;
                l2 = l2->next;
            } else if (l2 == NULL){
                next = l1;
                l1 = l1->next;
            } else{
                if (l1->val < l2->val){
                    next = l1;
                    l1 = l1->next;
                } else{
                    next = l2;
                    l2 = l2->next;
                }
            }
            if (head == NULL)
                head = tail = next;
            else{
                tail->next = next;
                tail = next;
            }
            next->next = NULL;
        }
        return head;
    }

public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        int L = lists.size();
        if (L == 0) return NULL;
        if (L == 1) return lists[0];
        ListNode *head = lists[0];
        for (int i = 1; i < L; i++) head = mergeTwo(head, lists[i]);
        return head;
    }
};