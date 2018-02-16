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
    int dfs(TreeNode *n, int &path) {
        int l = n->left ? dfs(n->left, path) : 0;
        int r = n->right? dfs(n->right, path) : 0;
        int lp = n->left && n->left->val == n->val? l + 1: 0;
        int rp = n->right && n->right->val == n->val? r + 1: 0;
        path = std::max(path, lp + rp);
        return std::max(lp, rp);

    }

public:
    int longestUnivaluePath(TreeNode *root) {
        if (!root) return 0;
        int path = 0;
        dfs(root, path);
        return path;
    }
};