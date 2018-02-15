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
    void invert(TreeNode * n){
        if (!n)
            return;
        TreeNode *left = n->left;
        TreeNode *right = n->right;
        n->left = right;
        n->right = left;
        invert(n->left);
        invert(n->right);
    }
public:
    TreeNode *invertTree(TreeNode *root) {
        invert(root);
        return root;
    }
};