//
// Created by Andrii Cherniak on 4/8/18.
//
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        int Ls = s.size();
        int Lp = p.size();
        vector<vector<bool> > dp = vector<vector<bool >>(Ls + 1, vector<bool>(Lp + 1, false));
        dp[0][0] = true;
        for (int i = 0; i <= Ls; i++)
            for (int j = 1; j <= Lp; j++) {
                if (p[j - 1] != '*')
                    dp[i][j] = (i > 0) && dp[i - 1][j - 1] && (s[i - 1] == p[j - 1] || p[j - 1] == '.');
                else {
                    dp[i][j] = dp[i][j - 2] || ((i > 0) && dp[i-1][j]&&(s[i-1] == p[j-2] || p[j-2] == '.'));
                }

            }
        return dp[Ls][Lp];
    }
};