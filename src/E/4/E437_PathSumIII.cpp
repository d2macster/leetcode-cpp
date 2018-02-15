//
// Created by Andrii Cherniak on 2/15/18.
//

#include <vector>
#include <unordered_map>
#include <iostream>

using std::vector;
using std::unordered_map;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {

    int dfs(TreeNode *n, int sum, unordered_map<int, int> &cache, int cur_sum) {
        if (!n) return 0;
        cur_sum += n->val;
        int diff = cur_sum - sum;

        int counter = (cur_sum == sum) + (cache.count(diff) ? cache[diff] : 0);

        cache[cur_sum]++;
        counter += dfs(n->left, sum, cache, cur_sum);
        counter += dfs(n->right, sum, cache, cur_sum);
        cache[cur_sum]--;
        return counter;
    }

public:
    int pathSum(TreeNode *root, int sum) {
        unordered_map<int, int> cache;
        return dfs(root, sum, cache, 0);
    }
};