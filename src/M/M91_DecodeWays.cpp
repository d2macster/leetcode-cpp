//
// Created by Andrii Cherniak on 1/16/18.
//
#include <string>
#include <iostream>

using std::string;

class Solution {
public:
    int numDecodings(string s) {
        int L = s.length();
        if (L == 0) return 0;
        int digits[L];
        for (int i = 0; i < L; i++)
            digits[i] = s[i] - '0';

        int dp[L];
        int ll;
        for (int i = 0; i < L; i++) dp[i] = 0;
        if (digits[0] > 0) dp[0] = 1;
        if (L >= 2) {
            if (digits[1] > 0) dp[1] = dp[0];
            ll = 10 * digits[0] + digits[1];
            if (ll >= 10 && ll <= 26) dp[1]++;
        }

        for (int i = 2; i < L; i++) {
            if (digits[i] > 0) dp[i] += dp[i - 1];
            ll = 10 * digits[i-1] + digits[i];
            if (ll >= 10 && ll <= 26) dp[i] += dp[i - 2];
        }
        return dp[L - 1];
    }
};