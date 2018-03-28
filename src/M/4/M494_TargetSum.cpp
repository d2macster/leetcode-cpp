//
// Created by Andrii Cherniak on 3/28/18.
//
#include <vector>
using namespace std;


class Solution {
    int ways = 0;
    void helper(vector<int>& nums, int S, int n_id, int cur_sum){
        if (n_id == nums.size()) {
            if (cur_sum == S) ways++;
            return;
        }
        helper(nums, S, n_id + 1, cur_sum + nums[n_id]);
        helper(nums, S, n_id + 1, cur_sum - nums[n_id]);

    }
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int s = 0;
        for (int n: nums) s += n;
        if (abs(s) < abs(S)) return 0;

        helper(nums, S, 0, 0);

        return ways;

    }
};