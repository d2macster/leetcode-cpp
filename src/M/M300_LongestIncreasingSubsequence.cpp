//
// Created by Andrii Cherniak on 1/17/18.
//

#include <vector>

using std::vector;

class Solution {
public:
    int lengthOfLIS(vector<int> &nums) {
        int L = nums.size();
        if (L == 0) return 0;
        int dp[L];
        for (int i = 0; i < L; i++) dp[i] = 0;

        int result = 0;

        for (int i = 0; i < L; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i]) dp[i] = std::max(dp[i], dp[j]);
            }
            dp[i] ++;
            result = std::max(result, dp[i]);
        }

        return result;
    }
};