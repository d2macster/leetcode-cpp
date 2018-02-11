//
// Created by Andrii Cherniak on 2/10/18.
//

#include <vector>
#include <string>

using std::vector;
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
    vector<string> binaryTreePaths(TreeNode *root) {
        vector<string> paths;
        if (root == NULL) return paths;
        for (string s: binaryTreePaths(root->left))
            paths.push_back(to_string(root->val) + "->" + s);
        for (string s: binaryTreePaths(root->right))
            paths.push_back(to_string(root->val) + "->" + s);
        if (paths.empty()) paths.push_back(to_string(root->val));
        return paths;
    }
};