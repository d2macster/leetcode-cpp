//
// Created by Andrii Cherniak on 4/3/18.
//
#include <vector>
#include <iostream>

using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    void dfs(TreeNode *n, vector<int> &boundary, bool lb, bool rb) {
        if (!n)return;
        if (lb) boundary.push_back(n->val);
        if (!lb && !rb && !n->left && !n->right) boundary.push_back(n->val);
        dfs(n->left, boundary, lb, rb && !n->right);
        dfs(n->right, boundary, lb && !n->left, rb);
        if (rb) boundary.push_back(n->val);
    }

public:
    vector<int> boundaryOfBinaryTree(TreeNode *root) {
        vector<int> boundary;
        if (!root)
            return boundary;
        boundary.push_back(root->val);

        dfs(root->left, boundary, true, false);
        dfs(root->right, boundary, false, true);

        return boundary;

    }
};