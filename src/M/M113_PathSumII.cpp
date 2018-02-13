//
// Created by Andrii Cherniak on 2/12/18.
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
    void dfs(TreeNode *n, int sum, int target, vector<vector<int> > & paths, vector<int> path){
        if (n != NULL) {
            path.push_back(n->val);
            sum += n->val;
            if (!n->left && !n->right && sum == target)
                paths.push_back(path);
            if (n->left != NULL) dfs(n->left, sum, target, paths, path);
            if (n->right != NULL) dfs(n->right, sum, target, paths, path);
        }
    }
public:
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        vector<vector<int> > paths;
        if (!root)
            return paths;
        dfs(root, 0, sum, paths, vector<int>());
        return paths;
    }
};