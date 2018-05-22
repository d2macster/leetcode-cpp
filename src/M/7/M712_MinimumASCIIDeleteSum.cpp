//
// Created by Andrii Cherniak on 5/21/18.
//
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int L1 = s1.size();
        int L2 = s2.size();
        vector<vector<int>> dp = vector<vector<int>>(L1 + 1, vector<int>(L2 + 1, 0));
        int cost = 0;
        for (int i = 1; i <= L1; i++) {
            cost += s1[i - 1];
            dp[i][0] = cost;
        }
        cost = 0;
        for (int j = 1; j <= L2; j++) {
            cost += s2[j - 1];
            dp[0][j] = cost;
        }
        for (int i = 1; i <= L1; i++) {
            for (int j = 1; j <= L2; j++) {
                if (s1[i - 1] == s2[j - 1]) dp[i][j] = dp[i - 1][j - 1];
                else {
                    int v1 = dp[i - 1][j - 1] + s1[i - 1] + s2[j - 1];
                    int v2 = dp[i - 1][j] + s1[i - 1];
                    int v3 = dp[i][j - 1] + s2[j - 1];
                    dp[i][j] = min(v3, min(v1, v2));
                }
            }
        }
        return dp[L1][L2];
    }
};