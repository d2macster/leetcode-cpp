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
    int dfs(TreeNode *n) {
        if (!n->left && !n->right) return 1;
        int ld = 999999, rd = 999999;
        if (n->left != NULL) ld = 1 + dfs(n->left);
        if (n->right != NULL) rd = 1 + dfs(n->right);
        return std::min(ld, rd);
    }

public:
    int minDepth(TreeNode *root) {
        if (root == NULL) return 0;
        return dfs(root);
    }
};