//
// Created by Andrii Cherniak on 5/29/18.
//
#include <vector>
#include <limits>

using namespace std;

class Solution {
public:
    int splitArray(vector<int> &nums, int m) {
        int n = nums.size();
        if (n < m)
            return 0;
        vector<vector<long>> dp = vector<vector<long>>(n + 1, vector<long>(m + 1, INT_MAX));
        vector<long> cumSum = vector<long>(n + 1, 0);
        for (int i = 0; i < n; i++) cumSum[i + 1] = cumSum[i] + nums[i];
        for (int i = 1; i <= n; i++) dp[i][1] = cumSum[i];
        dp[0][0] = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                for (int k = 0; k <= i; k++) dp[i][j] = min(dp[i][j], max(dp[k][j - 1], cumSum[i] - cumSum[k]));
            }
        }

        return (int) dp[n][m];
    }
};