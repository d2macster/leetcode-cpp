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
    void dfs(TreeNode *n, vector<int> &counter, vector<double> &sum, int level) {
        if (!n) return;
        if (sum.size() < level) {
            sum.push_back(0.0);
            counter.push_back(0);
        }
        sum[level - 1] += n->val;
        counter[level - 1] += 1;
        dfs(n->left, counter, sum, level + 1);
        dfs(n->right, counter, sum, level + 1);

    }

public:
    vector<double> averageOfLevels(TreeNode *root) {
        vector<int> counter;
        vector<double> sum;
        if (!root) return sum;
        dfs(root, counter, sum, 1);
        for (int i = 0; i < counter.size(); i++) sum[i] /= counter[i];
        return sum;
    }
};