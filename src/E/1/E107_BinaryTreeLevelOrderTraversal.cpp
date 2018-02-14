//
// Created by Andrii Cherniak on 2/14/18.
//
#include <vector>
#include <algorithm>
using std::vector;
using std::reverse;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    void dfs(TreeNode * n, vector<vector<int> > & result, int level){
        if (!n) return;
        if (level > result.size()) result.push_back(vector<int>());
        result[level-1].push_back(n->val);
        dfs(n->left, result, level + 1);
        dfs(n->right, result, level + 1);

    }
public:
    vector <vector<int> > levelOrderBottom(TreeNode *root) {
        vector<vector<int> > result;
        dfs(root, result, 1);
        reverse(result.begin(), result.end());
        return result;
    }
};