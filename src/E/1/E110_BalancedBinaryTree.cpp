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
    bool balanced = true;

    int depth(TreeNode *root, int d) {
        if (root == NULL || !balanced) return d;
        else {
            int dl = depth(root->left, d + 1);
            int dr = depth(root->right, d + 1);
            if (abs(dl - dr) > 1) balanced = false;
            return std::max(dl, dr);
        }
    }

public:
    bool isBalanced(TreeNode *root) {
        depth(root, 1);
        return balanced;
    }
};