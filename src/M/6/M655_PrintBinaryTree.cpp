//
// Created by Andrii Cherniak on 3/10/18.
//
#include <vector>
#include <string>

using std::string;
using std::vector;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    int getH(TreeNode *n) {
        if (!n) return 0;
        return 1 + std::max(getH(n->left), getH(n->right));
    }

    void printTree(TreeNode *n, vector<vector<string> > &result, int level, int l, int r) {
        if (!n) return;
        int mid = (l+r)/2;
        result[level][(l+r)/2] = std::to_string(n->val);
        printTree(n->left, result, level+1, l, mid-1);
        printTree(n->right, result, level+1, mid+1, r);
    }

public:
    vector<vector<string> > printTree(TreeNode *root) {
        if (!root)
            return vector<vector<string>>();
        int h = getH(root);
        int w = (1 << h) - 1;
        vector<vector<string>> result = vector<vector<string> >(h, vector<string>(w, ""));
        printTree(root, result, 0, 0, w - 1);
        return result;
    }
};