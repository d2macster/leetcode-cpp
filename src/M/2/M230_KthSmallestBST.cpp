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
    int counter = 0;
    int v;
    void dfs(TreeNode * n, int k){
        if (!n || counter >= k) return;
        dfs(n->left, k);
        if (++counter == k){
            v = n->val;
            return;
        }
        dfs(n->right, k);

    }
public:
    int kthSmallest(TreeNode *root, int k) {
        dfs(root, k);
        return v;
    }
};