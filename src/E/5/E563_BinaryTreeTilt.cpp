//
// Created by Andrii Cherniak on 3/1/18.
//


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    int tilt = 0;
    int sum(TreeNode *n) {
        if (!n) return 0;
        n->val += sum(n->left);
        n->val += sum(n->right);
        return n->val;
    }
    int nodeTilt(TreeNode *n){
        if (!n) return 0;
        tilt += abs(nodeTilt(n->left) - nodeTilt(n->right));
        return n->val;
    }

public:
    int findTilt(TreeNode *root) {
        if (!root) return 0;
        tilt = 0;
        sum(root);
        nodeTilt(root);
        return tilt;
    }
};