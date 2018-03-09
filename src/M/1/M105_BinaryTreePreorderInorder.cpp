//
// Created by Andrii Cherniak on 3/9/18.
//

#include <vector>
#include <iostream>
#include <unordered_map>

using std::vector;
using std::unordered_map;
using std::cout;
using std::endl;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    unordered_map<int, int> m;

    TreeNode *helper(vector<int> &preorder, vector<int> &inorder, int l, int r, int ll, int rr) {

        if (l > r || ll > rr) return nullptr;
        int root_val = preorder[l];
        int root_id = m[root_val];
        int inLeft = root_id - ll;

        TreeNode *root = new TreeNode(root_val);
        root->left = helper(preorder, inorder, l+1, l + inLeft, ll, root_id - 1);
        root->right = helper(preorder, inorder, l + inLeft + 1, r, root_id + 1, rr);
        return root;
    }

public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        int L = preorder.size();
        for (int i = 0; i < L; i++) m[inorder[i]] = i;
        return helper(preorder, inorder, 0, L - 1, 0, L - 1);
    }
};