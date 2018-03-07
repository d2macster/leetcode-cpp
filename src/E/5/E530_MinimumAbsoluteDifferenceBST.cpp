//
// Created by Andrii Cherniak on 3/6/18.
//

#include <limits>
#include <algorithm>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    long prev = INT_MIN;
    long d = INT_MAX;
    void dfs(TreeNode * n){
        if (!n) return;
        dfs(n->left);

        d = std::min(d, abs(n->val - prev));
        prev = n->val;
        dfs(n->right);
    }
public:
    int getMinimumDifference(TreeNode *root) {
        if (!root) return 0;
        dfs(root);
        return int(d);
    }
};