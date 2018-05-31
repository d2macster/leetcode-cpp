//
// Created by Andrii Cherniak on 5/30/18.
//
#include <vector>
#include <limits>

using namespace std;

class Solution {
public:
    int maxCoins(vector<int> &nums) {
        if (nums.empty()) return 0;
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        int L = nums.size();
        vector<vector<int>> dp = vector<vector<int>>(L, vector<int>(L, INT_MIN));

            for(int r = 1; r <= L - 2; r++) {
                for(int l = r; l > 0; l--) {
                    for (int k = l; k <= r; k++)
                        dp[l][r] = max(dp[l][r], max(0, dp[l][k - 1]) + nums[l - 1] * nums[k] * nums[r + 1] + max(0, dp[k + 1][r]));
                }
            }


        return dp[1][L - 2];
    }
};