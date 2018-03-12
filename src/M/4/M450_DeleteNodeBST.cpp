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
    TreeNode* findMinNode(TreeNode* root) {
        if (root->left) return findMinNode(root->left);
        return root;
    }
public:
    TreeNode *deleteNode(TreeNode *root, int key) {
        if (!root) return nullptr;
        if (key == root->val) {
            if (!root->right) {
                TreeNode * left = root->left;
                delete root;
                return left;
            }else if (!root->left){
                TreeNode * right = root->right;
                delete root;
                return right;
            } else{
                TreeNode * successor = findMinNode(root->right);
                root->val = successor->val;
                root->right = deleteNode(root->right, successor->val);
            }
        } else if (key < root->val) {
            root->left = deleteNode(root->left, key);
        } else {
            root->right = deleteNode(root->right, key);
        }
        return root;
    }
};