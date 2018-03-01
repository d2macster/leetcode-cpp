//
// Created by Andrii Cherniak on 3/1/18.
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
    void helper(TreeNode *n, vector<int> &result){
        if (!n)
            return;
        helper(n->left, result);
        result.push_back(n->val);
        helper(n->right, result);
    }
public:
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> result;
        helper(root, result);
        return result;
    }
};