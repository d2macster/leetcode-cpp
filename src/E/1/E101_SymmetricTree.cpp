//
// Created by Andrii Cherniak on 2/10/18.
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
public:
    bool isSymmetric(TreeNode *root) {
        if (root == NULL)
            return true;
        vector<TreeNode *> t1, t2;
        t1.push_back(root);
        while (t1.size() > 0){
            int p1 = 0, p2 = t1.size() - 1;
            while (p1 < p2){
                if (t1[p1] == NULL ^ t1[p2] == NULL) return false;
                if (t1[p1] != NULL && t1[p1]->val != t1[p2]->val) return false;
                p1 ++;
                p2 --;
            }
            for(TreeNode * t: t1){
                if (t != NULL) {
                    t2.push_back(t->left);
                    t2.push_back(t->right);
                }
            }
            std::swap(t1, t2);
            t2.clear();
        }
        return true;
    }
};