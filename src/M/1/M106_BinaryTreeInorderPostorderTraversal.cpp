//
// Created by Andrii Cherniak on 3/10/18.
//
#include <vector>
#include <unordered_map>

using std::vector;
using std::unordered_map;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    unordered_map<int, int> i_pos;

    TreeNode *helper(vector<int> &inorder, vector<int> &postorder, int li, int ri, int lp, int rp) {
        if (li > ri || lp > rp) return nullptr;
        int root_v = postorder[rp];
        int root_i_pos = i_pos[root_v];
        TreeNode *root = new TreeNode(root_v);
        root->left = helper(inorder, postorder, li, root_i_pos - 1, lp, lp + (root_i_pos - li) - 1);
        root->right = helper(inorder, postorder, root_i_pos + 1, ri, lp + (root_i_pos - li), rp - 1);

        return root;
    }

public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        int Li = inorder.size();
        int Lp = postorder.size();
        if (!Li || !Lp || Li != Lp) return nullptr;

        for (int i = 0; i < Li; i++) i_pos[inorder[i]] = i;
        return helper(inorder, postorder, 0, Li - 1, 0, Li - 1);
    }
};