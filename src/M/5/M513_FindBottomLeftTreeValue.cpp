//
// Created by Andrii Cherniak on 3/2/18.
//
#include <unordered_map>

using std::unordered_map;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    int dfs(TreeNode *n, unordered_map<int, int> &m, int level) {
        if (!n) return -1;
        int l1 = dfs(n->left, m, level + 1);
        if (m.find(level) == m.end()) m[level] = n->val;
        int l2 = dfs(n->right, m, level + 1);
        return std::max(level, std::max(l1, l2));
    }

public:
    int findBottomLeftValue(TreeNode *root) {
        if (!root)
            return 0;
        unordered_map<int, int> m;
        int maxl = dfs(root, m, 1);
        return m[maxl];
    }
};
