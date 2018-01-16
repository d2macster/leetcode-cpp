//
// Created by Andrii Cherniak on 1/16/18.
//

#include <vector>
#include <iostream>

using std::vector;

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int L = prices.size();
        if (L <= 1) return 0;

        int dp[L][3];
        for (int i = 0; i < L; i++)
            dp[i][0] = dp[i][1] = dp[i][2] = 0;
        dp[0][0] = -prices[0];

        for (int i = 1; i < L; i++) {
            dp[i][0] = std::max(dp[i - 1][0], dp[i - 1][2] - prices[i]);
            dp[i][1] = std::max(dp[i - 1][1], dp[i - 1][0] + prices[i]);
            dp[i][2] = std::max(dp[i - 1][2], dp[i - 1][1]);
        }

        return std::max(dp[L - 1][1], dp[L - 1][2]);
    }
};