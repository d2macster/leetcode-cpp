//
// Created by Andrii Cherniak on 2/15/18.
//
#include <iostream>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    void getMaxFreq(TreeNode *n, int &max_count, int & prev_val, int & cnt) {
        if (!n) return;
        getMaxFreq(n->left, max_count, prev_val, cnt);

        cnt = (prev_val == n->val)? cnt + 1: 1;
        prev_val = n->val;
        max_count = std::max(max_count, cnt);

        getMaxFreq(n->right, max_count, prev_val, cnt);
    }

    void getMode(TreeNode *n, int max_count, int & prev_val, int & cnt, vector<int> &modes) {
        if (!n) return;
        getMode(n->left, max_count, prev_val, cnt, modes);

        cnt = (prev_val == n->val)? cnt + 1: 1;
        prev_val = n->val;
        if (cnt == max_count) modes.push_back(n->val);

        getMode(n->right, max_count, prev_val, cnt, modes);
    }

public:
    vector<int> findMode(TreeNode *root) {
        vector<int> modes;
        if (!root)
            return modes;
        int max_count = 0, prev_val = -99999, cnt = 0;
        getMaxFreq(root, max_count, prev_val, cnt);
        getMode(root, max_count, prev_val, cnt = 0, modes);

        return modes;
    }
};