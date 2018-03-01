//
// Created by Andrii Cherniak on 3/1/18.
//
#include <limits>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    int sum = 0;

    void dfs(TreeNode *root) {
        if (root->right != NULL) dfs(root->right);
        root->val += sum;
        sum = root->val;
        if (root->left != NULL) dfs(root->left);
    }

public:
    TreeNode *convertBST(TreeNode *root) {
        if (!root) return NULL;
        sum = 0;
        dfs(root);
        return root;
    }
};