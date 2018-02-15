//
// Created by Andrii Cherniak on 2/15/18.
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
    int dfs(TreeNode *n, int sum, vector<int> path_sums){
        if (!n) return 0;
        int counter = 0;
        vector<int> n_sums = path_sums;
        for (int i = 0; i < n_sums.size(); i++) n_sums[i] += n->val;
        n_sums.push_back(n->val);
        for (int s: n_sums) counter += (s == sum)? 1 : 0;
        counter += dfs(n->left, sum, n_sums);
        counter += dfs(n->right, sum, n_sums);
        return counter;
    }

public:
    int pathSum(TreeNode *root, int sum) {
        return dfs(root, sum, vector<int>());
    }
};