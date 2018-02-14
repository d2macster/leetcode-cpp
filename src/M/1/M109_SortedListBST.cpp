//
// Created by Andrii Cherniak on 2/12/18.
//


struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    TreeNode *helper(ListNode *head, ListNode *tail) {
        if (head == tail)
            return NULL;
        ListNode *p1 = head, *p2 = head->next;
        while (p2 != tail && p2->next != tail) {
            p1 = p1->next;
            p2 = p2->next->next;
        }
        TreeNode *n = new TreeNode(p1->val);
        n->left = helper(head, p1);
        n->right = helper(p1->next, tail);
        return n;
    }

public:
    TreeNode *sortedListToBST(ListNode *head) {
        if (!head) return NULL;
        return helper(head, NULL);
    }
};