//
// Created by Andrii Cherniak on 1/16/18.
//

class Solution {
public:
    int integerBreak(int n) {
        if (n <= 0)
            return 0;

        int dp[n+1];
        for (int i = 0; i <= n; i++) dp[i] = 0;
        dp[0] = 0;
        dp[1] = 1;
        for (int v = 2; v < n; v++){
            for (int i = 1; i < v; i++){
                dp[v] = std::max(dp[v], dp[i] * dp[v-i]);
            }
            dp[v] = std::max(v, dp[v]);
        }

        for (int i = 1; i < n; i++){
            dp[n] = std::max(dp[n], dp[i] * dp[n-i]);
        }
        return dp[n];
    }
};