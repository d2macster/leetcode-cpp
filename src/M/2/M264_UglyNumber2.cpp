//
// Created by Andrii Cherniak on 1/17/18.
//
class Solution {
public:
    int nthUglyNumber(int n) {
        if (n == 1)
            return 1;

        int dp[n];
        dp[0] = 1;
        int p2, p3, p5, v;
        p2 = p3 = p5 = 0;
        for (int i = 1; i < n; i++){
            v = std::min(std::min(dp[p2] * 2, dp[p3] * 3), dp[p5] * 5);
            if (v == dp[p2] * 2) p2 ++;
            if (v == dp[p3] * 3) p3 ++;
            if (v == dp[p5] * 5) p5 ++;
            dp[i] = v;
        }
        return dp[n-1];
    }
};