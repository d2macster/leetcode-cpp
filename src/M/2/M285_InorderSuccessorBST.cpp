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
public:
    TreeNode *inorderSuccessor(TreeNode *root, TreeNode *p) {
        if (!root || !p) return NULL;

        TreeNode * succ = NULL;
        while (root){
            if (p->val >= root->val) root = root->right;
            else {
                succ = root;
                root = root->left;
            }
        }
        return succ;
    }
};