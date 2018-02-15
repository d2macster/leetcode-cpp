//
// Created by Andrii Cherniak on 2/14/18.
//


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
        if (!root || !p || !q) return NULL;
        if ((p->val - root->val) * (q->val - root->val) > 0){
            if (p->val < root->val) return lowestCommonAncestor(root->left, p, q);
            else return lowestCommonAncestor(root->right, p, q);
        }else return root;
    }
};