//
// Created by Andrii Cherniak on 3/8/18.
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
    void dfs(TreeNode * n, vector<int> & result, int level){
        if (!n) return;
        if (result.size() < level) result.push_back(n->val);
        else result[level-1] = std::max(result[level-1], n->val);
        dfs(n->left, result, level+1);
        dfs(n->right, result, level+1);
    }
public:
    vector<int> largestValues(TreeNode *root) {
        vector<int > result;
        dfs(root, result, 1);
        return result;
    }
};