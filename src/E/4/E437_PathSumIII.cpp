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
    void dfs(TreeNode *n, int sum, vector<int> &path_sums, int level, int & counter){
        if (!n) return;
        if (path_sums.size() < level) path_sums.push_back(0);

        for (int i = 0; i < level; i++) path_sums[i] += n->val;
        for (int i = 0; i < level; i++) counter += (path_sums[i] == sum)? 1 : 0;
        dfs(n->left, sum, path_sums, level + 1, counter);
        dfs(n->right, sum, path_sums, level + 1, counter);

        for (int i = 0; i < level; i++) path_sums[i] -= n->val;
    }

public:
    int pathSum(TreeNode *root, int sum) {
        vector<int> path_sums;
        int counter = 0;
        dfs(root, sum, path_sums, 1, counter);
        return counter;
    }
};