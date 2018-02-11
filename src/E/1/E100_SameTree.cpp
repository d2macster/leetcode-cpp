//
// Created by Andrii Cherniak on 2/10/18.
//


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isSameTree(TreeNode *p, TreeNode *q) {
        if (p == NULL && q == NULL) return true;
        if (p == NULL ^ q == NULL) return false;
        if (p->val != q->val) return false;
        if (p->left == NULL ^ q->left == NULL) return false;
        if (q->right == NULL ^ p->right == NULL) return false;
        return isSameTree(p->right, q->right) && isSameTree(p->left,q->left);
    }
};