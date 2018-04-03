//
// Created by Andrii Cherniak on 4/3/18.
//
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

class Solution {
    unordered_map<int, unordered_map<int, int>> tree;

    bool nodeExists(int level, int pos) {
        if (tree.find(level) == tree.end()) return false;
        if (tree[level].find(pos) == tree[level].end()) return false;
        return true;
    }

    void dfs(int level, int pos, int cum_val, int &sum) {
        cum_val += tree[level][pos];
        if (!nodeExists(level + 1, 2 * pos - 1) && !nodeExists(level + 1, 2 * pos)) {
            sum += cum_val;
            return;
        }
        if (nodeExists(level + 1, 2 * pos - 1)) dfs(level + 1, 2 * pos - 1, cum_val, sum);
        if (nodeExists(level + 1, 2 * pos)) dfs(level + 1, 2 * pos, cum_val, sum);

    }

public:
    int pathSum(vector<int> &nums) {
        if (nums.empty()) return 0;
        for (int n: nums) {
            int val = n % 10;
            n /= 10;
            int pos = n % 10;
            int level = n / 10;
            tree[level][pos] = val;
        }

        int sum = 0;
        dfs(1, 1, 0, sum);

        return sum;
    }
};