//
// Created by Andrii Cherniak on 2/13/18.
//


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    void flatten(TreeNode *root) {
        if (!root)
            return;
        flatten(root->left);
        flatten(root->right);
        TreeNode * left = root->left;
        TreeNode * right = root->right;
        root->left = NULL;
        root->right = left;
        while (root->right != NULL) root = root->right;
        root->right = right;

    }
};