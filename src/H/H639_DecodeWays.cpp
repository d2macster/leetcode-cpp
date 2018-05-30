//
// Created by Andrii Cherniak on 5/29/18.
//
#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        if (s == "") return 0;
        long m = 1000000007;
        int L = s.size();
        vector<long> dp = vector<long>(L + 1, 0);
        dp[0] = 1;
        if ('1' <= s[0] && s[0] <= '9') dp[1] = 1;
        if (s[0] == '*') dp[1] = 9;

        for (int i = 1; i < L; i++) {
            if (s[i] == '*') {
                dp[i + 1] = 9 * dp[i];
                if (s[i - 1] == '1') dp[i + 1] = (dp[i + 1] + 9 * dp[i - 1]) % m;
                else if (s[i - 1] == '2') dp[i + 1] = (dp[i + 1] + 6 * dp[i - 1]) % m;
                else if (s[i - 1] == '*') dp[i + 1] = (dp[i + 1] + 15 * dp[i - 1]) % m;
            } else {
                if (s[i] != '0') dp[i + 1] = dp[i] % m;
                if (s[i - 1] == '1') dp[i + 1] = (dp[i + 1] + dp[i - 1]) % m;
                else if (s[i - 1] == '2' && s[i] <= '6')dp[i + 1] = (dp[i + 1] + dp[i - 1]) % m;
                else if (s[i - 1] == '*') {
                    if (s[i] <= '6') dp[i + 1] = (dp[i + 1] + 2 * dp[i - 1]) % m;
                    else dp[i + 1] = (dp[i + 1] + dp[i - 1]) % m;
                }
            }
        }

       return (int) (dp[L] % m);
    }
};