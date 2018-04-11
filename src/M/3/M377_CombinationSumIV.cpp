//
// Created by Andrii Cherniak on 4/11/18.
//
#include <vector>

using namespace std;

class Solution {
public:
    int combinationSum4(vector<int> &nums, int target) {
        if (target < 0) return 0;
        int L = nums.size();
        sort(nums.begin(), nums.end());
        vector<int> dp = vector<int>(target + 1, 0);
        dp[0] = 1;
        for(int i = 1; i <= target; i++){
            for (int j = 0; j < L && nums[j] <= i; j++){
                int diff = i - nums[j];
                if (diff >= 0) {
                    dp[i] += dp[diff];
                }
            }
        }
        return dp[target];
    }
};