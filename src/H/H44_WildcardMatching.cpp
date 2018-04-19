//
// Created by Andrii Cherniak on 4/18/18.
//
#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        int Ls = s.size();
        int Lp = p.size();
        if (Lp == 0) return (Ls == 0);
        if (Ls == 0) return (p == "*");

        vector<vector<bool >> DP = vector<vector<bool >>(Ls + 1, vector<bool>(Lp + 1, false));
        DP[0][0] = true;
        for (int j = 0; j < Lp && p[j] == '*'; j++)DP[0][j+1] = true;

        for (int j = 1; j <= Lp; j++){
            for (int i = 1; i <= Ls; i++){
                if (p[j-1] == '*') DP[i][j] = DP[i-1][j] || DP[i][j-1];
                else DP[i][j] = (p[j-1] == s[i-1] || p[j-1] == '?') && DP[i-1][j-1];
            }
        }

        return DP[Ls][Lp];
    }
};