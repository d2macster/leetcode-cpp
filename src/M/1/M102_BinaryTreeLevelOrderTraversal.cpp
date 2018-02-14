//
// Created by Andrii Cherniak on 2/14/18.
//

#include <vector>
#include <iostream>

using std::vector;
using std::cout;
using std::endl;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<vector<int> > levelOrder(TreeNode *root) {
        vector<vector<int> > result;
        if (!root)
            return result;
        vector<TreeNode *> l1, l2;
        l1.push_back(root);
        while (!l1.empty()) {
            vector<int> v;
            for(TreeNode * p: l1){
                v.push_back(p->val);
                if (p->left != NULL) l2.push_back(p->left);
                if (p->right != NULL) l2.push_back(p->right);
            }
            result.push_back(v);
            l1 = l2;
            l2.clear();
        }
        return result;
    }
};