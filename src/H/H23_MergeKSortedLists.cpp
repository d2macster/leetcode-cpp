//
// Created by Andrii Cherniak on 4/6/18.
//

#include <vector>
#include <queue>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};
struct comparator{
    bool operator()(ListNode * l1, ListNode * l2){
        return (l1->val > l2->val);
    }
};

class Solution {


public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        int L = lists.size();
        if (L == 0) return NULL;
        if (L == 1) return lists[0];
        ListNode *head = NULL;
        ListNode * tail = NULL;
        priority_queue<ListNode*, vector<ListNode*>, comparator> q;
        for (int i = 0; i < L; i++)
            if (lists[i] != NULL) q.push(lists[i]);
        while (!q.empty()){
            ListNode* n = q.top();
            q.pop();
            if (n->next != NULL) q.push(n->next);

            if (head == NULL) head = tail = n;
            else{
                tail->next = n;
                tail = n;
            }
            n->next = NULL;
        }
        return head;
    }
};