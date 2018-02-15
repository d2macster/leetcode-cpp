//
// Created by Andrii Cherniak on 2/14/18.
//


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode *mergeTrees(TreeNode *t1, TreeNode *t2) {
        if (!t1 && !t2) return NULL;
        if (!t1) {
            t2->left = mergeTrees(NULL, t2->left);
            t2->right = mergeTrees(NULL, t2->right);
            return t2;
        }
        if (!t2) {
            t1->left = mergeTrees(t1->left, NULL);
            t1->right = mergeTrees(t1->right, NULL);
            return t1;
        }
        t1->left = mergeTrees(t1->left, t2->left);
        t1->right = mergeTrees(t1->right, t2->right);
        t1->val += t2->val;
        return t1;
    }
};