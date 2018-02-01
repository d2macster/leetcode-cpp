//
// Created by Andrii Cherniak on 2/1/18.
//

#include <iostream>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool isPalindrome(ListNode *head) {
        int L = 0;
        ListNode * p = head;
        while (p != NULL) {
            p = p->next;
            L++;
        }
        if (L <= 1) return true;
        int mid = (L % 2 == 0)? (L/2 - 1): L/2;

        p = head;
        for (int i = 1; i <= mid; i++) p = p->next;
        ListNode * p_brake = p;
        ListNode * p2 = p->next;
        ListNode * p3;
        while (p2 != NULL){
            p3 = p2->next;
            p2->next = p;
            p = p2;
            p2 = p3;
        }

        p_brake->next = NULL;

        p2 = p;
        p = head;

        while (p != NULL &&  p2 != NULL){
            cout << p->val << " " << p2->val << endl;
            if (p->val != p2->val) return false;
            p = p->next;
            p2 = p2->next;
        }

        return true;
    }
};