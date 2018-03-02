//
// Created by Andrii Cherniak on 3/2/18.
//


struct TreeLinkNode {
    int val;
    TreeLinkNode *left, *right, *next;

    TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution {
public:
    void connect(TreeLinkNode *root) {

        TreeLinkNode *l2 = NULL, *l2_begin = NULL, *head = root;
        while (head) {
            l2_begin = NULL;
            for (TreeLinkNode *l1 = head; l1 != NULL; l1 = l1->next) {
                if (l1->left) {
                    if (!l2_begin)
                        l2_begin = l2 = l1->left;
                    else {
                        l2->next = l1->left;
                        l2 = l2->next;
                    }

                }
                if (l1->right) {
                    if (!l2_begin)
                        l2_begin = l2 = l1->right;
                    else {
                        l2->next = l1->right;
                        l2 = l2->next;
                    }
                }
            }
            head = l2_begin;
        }

    }
};