//
// Created by Andrii Cherniak on 1/15/18.
//

class Solution {
public:
    int numWays(int n, int k) {
        if (n == 0 || k == 0)
            return 0;
        if (n > 2 && k == 1)
            return 0;

        int dp[n][2];
        dp[0][0] = k;
        dp[0][1] = 0;
        for (int i = 1; i < n; i++){
            dp[i][0] = (dp[i-1][1] + dp[i-1][0]) * (k-1);
            dp[i][1] = dp[i-1][0];
        }

        return dp[n-1][0] + dp[n-1][1];
    }
};