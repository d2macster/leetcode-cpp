//
// Created by Andrii Cherniak on 2/15/18.
//


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    bool sameTree(TreeNode *s, TreeNode *t) {
        if (!s && !t) return true;
        if (!s || !t) return false;
        if (s->val != t->val) return false;
        return sameTree(s->left, t->left) && sameTree(s->right, t->right);
    }

public:
    bool isSubtree(TreeNode *s, TreeNode *t) {
        if (!s && !t) return true;
        if (!s || !t) return false;
        if (s->val == t->val && sameTree(s, t)) return true;
        if (isSubtree(s->left, t)) return true;
        if (isSubtree(s->right, t)) return true;
        return false;
    }
};