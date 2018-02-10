//
// Created by Andrii Cherniak on 2/10/18.
//


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int maxDepth(TreeNode *root) {
        return (root == NULL) ? 0 : 1 + std::max(maxDepth(root->left), maxDepth(root->right));
    }
};