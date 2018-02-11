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
    bool dfs(TreeNode *n, int sum, int acc) {
        acc += n->val;
        if (!n->left && !n->right) return (acc == sum);
        if (n->left != NULL && dfs(n->left, sum, acc)) return true;
        if (n->right != NULL && dfs(n->right, sum, acc)) return true;
        return false;
    }

public:
    bool hasPathSum(TreeNode *root, int sum) {
        if (root == NULL) return false;
        return dfs(root, sum, 0);
    }
};