//
// Created by Andrii Cherniak on 2/13/18.
//
#include <vector>

using std::vector;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    int dfs(TreeNode *n, vector<vector<int> > &result) {
        if (!n) return 0;
        int level = std::max(dfs(n->left, result), dfs(n->right, result)) + 1;
        if (level > int(result.size())) result.push_back(vector<int>());
        result[level-1].push_back(n->val);
        return level;
    }

public:
    vector<vector<int> > findLeaves(TreeNode *root) {
        vector<vector<int> > result;
        dfs(root, result);
        return result;
    }
};