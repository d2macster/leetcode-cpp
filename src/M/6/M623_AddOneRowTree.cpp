//
// Created by Andrii Cherniak on 4/3/18.
//


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    TreeNode *helper(TreeNode *root, int v, int d, int cur_d) {
        if (!root) return NULL;
        if (cur_d == d-1){
            TreeNode * n1 = new TreeNode(v);
            TreeNode * n2 = new TreeNode(v);

            n1->left = root->left;
            n2->right = root->right;

            root->left = n1;
            root->right = n2;

            return root;
        } else if (cur_d < d - 1){
            root->left = helper(root->left, v, d, cur_d+1);
            root->right = helper(root->right, v, d, cur_d+1);
            return root;
        }

    }
public:
    TreeNode *addOneRow(TreeNode *root, int v, int d) {
        if (d == 1){
            TreeNode * n = new TreeNode(v);
            n->left = root;
            return n;
        }

        return helper(root, v, d, 1);
    }
};