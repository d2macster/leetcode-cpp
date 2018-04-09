//
// Created by Andrii Cherniak on 4/9/18.
//
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        int L1 = word1.size();
        int L2 = word2.size();
        vector<vector<int >> dp = vector<vector<int >>(L1 + 1, vector<int>(L2 + 1, L1 + L2));

        dp[0][0] = 0;
        for (int i = 1; i <= L1; i++)
            dp[i][0] = i;
        for (int j = 1; j <= L2; j++)
            dp[0][j] = j;

        for (int i = 1; i <= L1; i++)
            for (int j = 1; j <= L2; j++) {
                if (word1[i - 1] == word2[j - 1]) dp[i][j] = dp[i - 1][j - 1];
                else dp[i][j] = 1 + min(min(dp[i-1][j-1], dp[i-1][j]), dp[i][j-1]);

            }
        return dp[L1][L2];
    }
};