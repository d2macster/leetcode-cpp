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
    void dfs(TreeNode *root, vector<int> &view, int depth) {
        if (root != NULL) {
            if (view.size() < depth) view.push_back(root->val);
            dfs(root->right, view, depth + 1);
            dfs(root->left, view, depth + 1);
        }
    }

public:
    vector<int> rightSideView(TreeNode *root) {
        vector<int> view;
        dfs(root, view, 1);
        return view;
    }
};