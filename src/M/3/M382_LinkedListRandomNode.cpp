//
// Created by Andrii Cherniak on 4/12/18.
//
#include <cstdlib>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
    ListNode * list_head = NULL;
public:
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    Solution(ListNode *head) {
        list_head = head;
    }

    /** Returns a random node's value. */
    int getRandom() {
        int L = 0;
        ListNode * head = list_head;
        ListNode * n = NULL;

        while (head != NULL){
            L++;
            double p_list = 1.0/L;
            double p = 1.0*rand()/RAND_MAX;
            if (p <= p_list) n = head;
            head = head->next;
        }

        return (n == NULL)?list_head->val:n->val;
    }
};