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
    bool dfs(TreeNode *l, TreeNode *r) {
        if (!l && !r) return true;
        else if (!l || !r ) return false;

        if (l->val != r->val) return false;
        if (!dfs(l->left, r->right)) return false;
        else return dfs(l->right, r->left);
    }

public:
    bool isSymmetric(TreeNode *root) {
        if (root == NULL) return true;
        return dfs(root->left, root->right);
    }
};