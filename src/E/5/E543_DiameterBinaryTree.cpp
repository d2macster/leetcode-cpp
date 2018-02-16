//
// Created by Andrii Cherniak on 2/15/18.
//

#include <iostream>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    int dfs(TreeNode * n, int &d){
        if (!n) return 0;
        int l = dfs(n->left, d);
        int r = dfs(n->right, d);
        d = std::max(d, l + r);
        return std::max(l, r) + 1;
    }
public:
    int diameterOfBinaryTree(TreeNode *root) {
        if (!root)
            return 0;
        int d = 0;
        dfs(root, d);
        return d;
    }
};