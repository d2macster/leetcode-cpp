//
// Created by Andrii Cherniak on 3/10/18.
//


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    bool dfs_helper(TreeNode *n, int &counter) {
        if (!n) return true;
        int l = dfs_helper(n->left, counter);
        int r = dfs_helper(n->right, counter);
        bool l_check = (!n->left || (l && n->left->val == n->val ));
        bool r_check = (!n->right || (r && n->right->val == n->val));
        if (l_check && r_check) {
            counter++;
            return true;
        } else return false;
    }

public:
    int countUnivalSubtrees(TreeNode *root) {
        int counter = 0;
        dfs_helper(root, counter);
        return counter;
    }
};