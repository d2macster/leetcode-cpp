//
// Created by Andrii Cherniak on 1/16/18.
//
#include <vector>
#include <iostream>

using std::vector;

class Solution {
public:
    int coinChange(vector<int> &coins, int amount) {
        if (amount == 0)
            return 0;
        int L = coins.size();
        if (L == 0) return -1;

        int dp[amount + 1];
        for (int i = 0; i <= amount; i++) dp[i] = 2 * amount;
        dp[0] = 0;
        int diff;
        for (int i = 1; i <= amount; i++) {
            for (int j = 0; j < L; j++) {
                diff = i - coins[j];
                if (diff >= 0) {
                    dp[i] = std::min(dp[i], dp[diff] + 1);
                }
            }
        }


        return (dp[amount] != 2 * amount) ? dp[amount] : -1;
    }
};