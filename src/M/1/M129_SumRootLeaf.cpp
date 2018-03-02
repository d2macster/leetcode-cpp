//
// Created by Andrii Cherniak on 3/2/18.
//


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    int sum = 0;

    void dfs(TreeNode *n, int v) {
        v = 10 * v + n->val;
        if (!n->left && !n->right) {
            sum += v;
            return;
        }

        if (n->left != NULL) dfs(n->left, v);
        if (n->right != NULL) dfs(n->right, v);
    }

public:
    int sumNumbers(TreeNode *root) {
        if (!root)
            return 0;
        dfs(root, 0);
        return sum;
    }
};