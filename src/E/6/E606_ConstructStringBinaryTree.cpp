//
// Created by Andrii Cherniak on 2/15/18.
//

#include <string>

using std::string;
using std::to_string;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    string tree2str(TreeNode *t) {
        if (!t) return "";
        string result = to_string(t->val);
        if (!t->left && !t->right)
            return result;
        string l = tree2str(t->left);
        string r = tree2str(t->right);
        result += "(" + l + ")";
        if (r != "") result += "(" + r + ")";
        return result;
    }
};