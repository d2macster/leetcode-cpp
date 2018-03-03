//
// Created by Andrii Cherniak on 3/2/18.
//

#include <vector>
#include <utility>

using std::vector;
using std::pair;
using std::make_pair;
using std::max;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    pair<int, int> dfs(TreeNode *n) {
        if (!n) return make_pair(0, 0);
        pair<int, int> left = dfs(n->left);
        pair<int, int> right = dfs(n->right);
        int chosen = left.second + right.second + n->val;
        int skipped = max(left.first, left.second) + max(right.first, right.second);
        return make_pair(chosen, skipped);
    }

public:
    int rob(TreeNode *root) {
        pair<int, int> result = dfs(root);
        return max(result.first, result.second);
    }
};