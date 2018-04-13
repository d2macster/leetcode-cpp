//
// Created by Andrii Cherniak on 4/13/18.
//
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int findMaxForm(vector<string> &strs, int m, int n) {
        int L = strs.size();
        if (L == 0) return 0;
        vector<vector<int>> dp = vector<vector<int>>(m + 1, vector<int>(n + 1, 0));

        for (int i = 0; i < L; i++) {
            int ones = 0;
            for (char c: strs[i]) ones += (c - '0');
            int zeros = strs[i].size() - ones;
            if (ones > n || zeros > m) continue;

            for (int z = m; z >= zeros; z--){
                for (int o = n; o >= ones; o--){
                    dp[z][o] = max(dp[z][o], 1 + dp[z-zeros][o-ones]);
                }
            }
        }
        return dp[m][n];

    }
};