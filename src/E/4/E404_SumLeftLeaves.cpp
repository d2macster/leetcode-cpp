//
// Created by Andrii Cherniak on 2/15/18.
//


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int sumOfLeftLeaves(TreeNode *root) {
        if (!root) return 0;
        int result = 0;
        if (root->left != NULL && !root->left->left && !root->left->right) result += root->left->val;
        result += sumOfLeftLeaves(root->left);
        result += sumOfLeftLeaves(root->right);
        return result;
    }
};