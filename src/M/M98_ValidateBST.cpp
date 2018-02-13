//
// Created by Andrii Cherniak on 2/12/18.
//

#include <limits>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    bool check_dfs(TreeNode *root, long min_v, long max_v){
        if (!root) return true;
        long v = long(root->val);
        if (v < min_v || v > max_v) return false;
        return check_dfs(root->left, min_v, std::min(max_v, v - 1L)) && check_dfs(root->right, std::max(min_v, v + 1), max_v);
    }
public:
    bool isValidBST(TreeNode *root) {
        return check_dfs(root, LONG_MIN, LONG_MAX);
    }
};