//
// Created by Andrii Cherniak on 3/8/18.
//
#include <vector>
#include <unordered_map>

using std::vector;
using std::unordered_map;
using std::max;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    int dfs_sum(TreeNode *n, unordered_map<int, int> &counter) {
        if (!n)
            return 0;
        int v = n->val + dfs_sum(n->left, counter) + dfs_sum(n->right, counter);
        counter[v]++;
        return v;
    }

public:
    vector<int> findFrequentTreeSum(TreeNode *root) {
        unordered_map<int, int> counter;
        vector<int> result;
        dfs_sum(root, counter);
        int maxFreq = 0;
        for (auto i: counter)
            maxFreq = max(maxFreq, i.second);

        for (auto i: counter)
            if (i.second == maxFreq) result.push_back(i.first);

        return result;
    }
};