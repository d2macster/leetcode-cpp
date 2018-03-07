//
// Created by Andrii Cherniak on 3/6/18.
//
#include <algorithm>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    bool is_prev = false;
    int prev = 0, d = 100000;
    void dfs(TreeNode * n){
        if (!n)
            return;
        dfs(n->left);
        if (!is_prev) {
            is_prev = true;
            prev = n->val;
        } else{
            d = std::min(d, n->val - prev);
            prev = n->val;
        }
        dfs(n->right);
    }
public:
    int minDiffInBST(TreeNode *root) {
        if (!root) return 0;
        dfs(root);
        return d;

    }
};