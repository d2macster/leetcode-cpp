//
// Created by Andrii Cherniak on 3/21/18.
//
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        int L1 = word1.size();
        int L2 = word2.size();
        if (!L1) return L2;
        if (!L2) return L1;

        vector<vector<int> > dp = vector<vector<int> >(L1 + 1, vector<int>(L2 + 1, 0));
        for (int i = 1; i <= L1; i++)
            for (int j = 1; j <= L2; j++) {
                if (word1[i-1] == word2[j-1]) dp[i][j] = dp[i-1][j-1] + 1;
                else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        return L1 + L2 - 2 * dp[L1][L2];


    }
};