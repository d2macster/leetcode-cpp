//
// Created by Andrii Cherniak on 3/2/18.
//

#include <stack>
#include <vector>

using std::stack;
using std::vector;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    void dfs(TreeNode * n, vector<int> & result){
        if (!n) return;
        result.push_back(n->val);
        dfs(n->left, result);
        dfs(n->right, result);
    }
public:
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> result;
        dfs(root, result);
        return result;
    }
};