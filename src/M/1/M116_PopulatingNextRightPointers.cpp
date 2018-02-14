//
// Created by Andrii Cherniak on 2/12/18.
//

struct TreeLinkNode {
    int val;
    TreeLinkNode *left, *right, *next;

    TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution {
public:
    void connect(TreeLinkNode *root) {
        if (root == NULL)
            return;
        TreeLinkNode * p, * pl = root;
        while (pl->left != NULL) {
            p = pl;
            while (p != NULL) {
                if (p->left != NULL) p->left->next = p->right;
                if (p->next != NULL) p->right->next = p->next->left;
                p = p->next;
            }
            pl = pl->left;
        }
    }
};