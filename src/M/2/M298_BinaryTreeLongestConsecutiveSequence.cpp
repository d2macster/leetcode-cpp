//
// Created by Andrii Cherniak on 3/11/18.
//
#include <limits>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    void dfs(TreeNode *n, int cur_path, int parent, int &best_path) {
        if (!n) return;
        if (n->val - parent == 1) cur_path += 1;
        else cur_path = 1;
        best_path = std::max(best_path, cur_path);
        dfs(n->left, cur_path, n->val, best_path);
        dfs(n->right, cur_path, n->val, best_path);
    }

public:
    int longestConsecutive(TreeNode *root) {
        int best_path = 0;
        dfs(root, 0, INT_MIN, best_path);
        return best_path;
    }
};