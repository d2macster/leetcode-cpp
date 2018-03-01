//
// Created by Andrii Cherniak on 2/28/18.
//
#include <cmath>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int closestValue(TreeNode *root, double target) {
        if (root->val == target)
            return target;
        int a = root->val;
        TreeNode * child = (target < a)? root->left : root->right;
        if (!child) return a;
        int b = closestValue(child, target);
        return (fabs(a - target) < fabs(b - target))? a : b;
    }
};