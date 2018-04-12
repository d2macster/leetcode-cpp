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
    int L = 0;
    ListNode * list_head = NULL;
public:
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    Solution(ListNode *head) {
        list_head = head;
        while (head != NULL){
            head = head->next;
            L++;
        }
    }

    /** Returns a random node's value. */
    int getRandom() {
        int node_id = rand() % L;
        int id = 0;
        ListNode * head = list_head;
        while (id < node_id && head != NULL) {
            head = head->next;
            id++;
        }
        return head->val;
    }
};