//
// Created by Andrii Cherniak on 1/16/18.
//

#include <cmath>
#include <iostream>

class Solution {
public:
    int numSquares(int n) {
        if (n <= 0)
            return 0;
        if (n == 1)
            return 1;
        int S = (int) std::sqrt(n);
        int sq[S];
        for (int i = 1; i <= S; i++) sq[i - 1] = i * i;
        int dp[n+1];
        for (int i = 0; i <= n; i++) dp[i] = n;
        dp[0] = 0;
        int v;
        for (int i = 1; i <= n; i++){
            for (int j = 0; j < S; j++){
                v = i - sq[j];
                if (v >= 0)
                dp[i] = std::min(dp[i], dp[v] + 1);
            }
        }

        return dp[n];
    }
};