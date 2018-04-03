//
// Created by Andrii Cherniak on 4/3/18.
//
#include <string>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    int pos = 0;
    TreeNode *helper(string &s) {
        string nodeStr = "";
        while(pos < s.size() && ((s[pos] >= '0' && s[pos] <= '9') || s[pos] == '-')){
            nodeStr += s[pos];
            pos++;
        }
        if (nodeStr == "")
            return NULL;
        TreeNode *node = new TreeNode(stoi(nodeStr));
        TreeNode *left = NULL, *right = NULL;
        if (s[pos] == '(') {
            pos ++;
            left = helper(s);
            pos++;
        }
        if (s[pos] == '(') {
            pos ++;
            right = helper(s);
            pos++;
        }

        node->left = left;
        node->right = right;

        return node;
    }

public:
    TreeNode *str2tree(string s) {
        return helper(s);
    }
};