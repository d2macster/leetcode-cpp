//
// Created by Andrii Cherniak on 3/6/18.
//
#include <unordered_map>

using std::unordered_map;

struct RandomListNode {
    int label;
    RandomListNode *next, *random;

    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if (!head)
            return NULL;
        unordered_map<RandomListNode *, RandomListNode *> mapping;
        RandomListNode * p = head, *p_new, *p_prev = NULL;

        while (p){
            p_new = new RandomListNode(p->label);
            mapping[p] = p_new;
            if (p_prev) mapping[p_prev]->next = p_new;
            p_prev = p;
            p = p->next;
        }

        p = head;
        while (p){
            if (p->random)mapping[p]->random = mapping[p->random];
            p = p->next;
        }

        return mapping[head];
    }
};