//
// Created by Andrii Cherniak on 3/10/18.
//
#include <vector>

using std::vector;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    vector<TreeNode *> getTree(int l, int r) {
        vector<TreeNode *> result;
        if (l > r) {
            result.push_back(nullptr);
            return result;
        }
        if (l == r){
            result.push_back(new TreeNode(l));
            return result;
        }
        for (int i = l; i <= r; i++) {
            vector<TreeNode *> left = getTree(l, i - 1);
            vector<TreeNode *> right = getTree(i + 1, r);
            for (TreeNode *lt: left) {
                for (TreeNode *rt: right) {
                    TreeNode *n = new TreeNode(i);
                    n->left = lt;
                    n->right = rt;
                    result.push_back(n);
                }
            }
        }
        return result;
    }

public:
    vector<TreeNode *> generateTrees(int n) {
        if (n < 1) return vector<TreeNode*>();
        return getTree(1, n);
    }
};