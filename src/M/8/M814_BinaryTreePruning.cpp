//
// Created by Andrii Cherniak on 5/21/18.
//
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    int dfs(TreeNode *n) {
        if (!n) return 0;
        int l = dfs(n->left);
        int r = dfs(n->right);
        if (l == 0) n->left = NULL;
        if (r == 0) n->right = NULL;
        return n->val + l + r;
    }

public:
    TreeNode *pruneTree(TreeNode *root) {
        int r = dfs(root);
        if (r == 0) return NULL;
        return root;
    }
};