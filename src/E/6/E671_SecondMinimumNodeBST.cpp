//
// Created by Andrii Cherniak on 3/1/18.
//
#include <limits>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {

    int SecondMinimum(TreeNode const *n, int min_val) {
        if (!n) return INT_MAX;
        if (n->val != min_val)
            return n->val;
        int left = SecondMinimum(n->left, min_val);
        int right = SecondMinimum(n->right, min_val);
        return min(left, right);
    }

public:
    int findSecondMinimumValue(TreeNode *root) {
        int m = SecondMinimum(root, root->val);
        return (m == INT_MAX) ? -1 : m;
    }
};