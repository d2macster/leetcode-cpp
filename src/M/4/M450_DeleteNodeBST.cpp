//
// Created by Andrii Cherniak on 3/11/18.
//


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode *deleteNode(TreeNode *root, int key) {
        if (!root) return nullptr;
        if (key == root->val){
            if (!root->right) {
                TreeNode *left = root->left;
                delete root;
                return left;
            }
            TreeNode * right = root->right;
            while (right->left) right = right->left;
            std::swap(root->val, right->val);
        }
        root->left = deleteNode(root->left, key);
        root->right = deleteNode(root->right, key);
        return root;
    }
};