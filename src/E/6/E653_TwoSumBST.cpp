//
// Created by Andrii Cherniak on 3/1/18.
//
#include <iostream>
#include <unordered_set>

using std::unordered_set;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    unordered_set<int> s;

    bool dfs(TreeNode *n, int k) {
        if (!n)
            return false;
        if (s.find(k-n->val) != s.end())
            return true;

        s.insert(n->val);
        return dfs(n->left, k) || dfs(n->right, k);
    }

public:
    bool findTarget(TreeNode *root, int k) {
        s.clear();
        return dfs(root, k);
    }
};