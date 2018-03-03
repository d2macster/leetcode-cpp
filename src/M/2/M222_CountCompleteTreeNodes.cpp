//
// Created by Andrii Cherniak on 3/2/18.
//


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    int getLeftHeight(TreeNode *n) {
        int depth = 0;
        while (n != NULL){
            depth++;
            n = n->left;
        }
        return depth;
    }

    int getRightHeight(TreeNode *n) {
        int depth = 0;
        while (n != NULL){
            depth++;
            n = n->right;
        }
        return depth;
    }

public:
    int countNodes(TreeNode *root) {
        if (!root)
            return 0;
        int l = getLeftHeight(root);
        int r = getRightHeight(root);
        return (l == r) ? (1 << l) - 1:
               1 + countNodes(root->right) + countNodes(root->left);
    }
};