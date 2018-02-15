//
// Created by Andrii Cherniak on 2/14/18.
//

#include <vector>
#include <algorithm>

using std::vector;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    void dfs(TreeNode *n, vector<vector<int> > &result, int level) {
        if (!n) return;
        if (result.size() < level) result.push_back(vector<int>());
        result[level - 1].push_back(n->val);
        dfs(n->left, result, level + 1);
        dfs(n->right, result, level + 1);
    }

public:
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        vector<vector<int> > result;
        if (!root) return result;
        dfs(root, result, 1);
        for (int l = 1; l <= result.size(); l++)
            if (l % 2 == 0) std::reverse(result[l-1].begin(), result[l-1].end());
        return result;
    }
};