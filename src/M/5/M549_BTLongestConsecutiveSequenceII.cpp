//
// Created by Andrii Cherniak on 4/5/18.
//

#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    vector<int> helper(TreeNode *n, int &maxL) {
        vector<int> seq = vector<int>(2, 0);
        if (!n) return seq;

        int incL = 0, incR = 0, decL = 0, decR = 0;

        if (n->left != NULL) {
            vector<int> left = helper(n->left, maxL);
            if (n->left->val == n->val - 1) incL = left[0];
            if (n->left->val == n->val + 1) decL = left[1];
        }
        if (n->right != NULL) {
            vector<int> right = helper(n->right, maxL);
            if (n->right->val == n->val - 1) incR = right[0];
            if (n->right->val == n->val + 1) decR = right[1];
        }
        maxL = max(maxL, incL + decR + 1);
        maxL = max(maxL, decL + incR + 1);
        seq[0] = max(incL, incR) + 1;
        seq[1] = max(decL, decR) + 1;
        return seq;
    }

public:
    int longestConsecutive(TreeNode *root) {
        if (!root) return 0;
        int maxL = 0;
        helper(root, maxL);
        return maxL;
    }
};