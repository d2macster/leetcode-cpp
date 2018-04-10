//
// Created by Andrii Cherniak on 4/10/18.
//
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int L = s.size();
        if (L <= 1) return L;
        vector<vector<int>> dp = vector<vector<int>>(L, vector<int>(L, 0));
        int maxL = 1;
        for (int i = 0; i < L; i++) dp[i][i] = 1;
        for(int d = 1; d < L; d++){
            for (int begin = 0; begin < L; begin++){
                if (begin + d < L){
                    if (s[begin] == s[begin + d]) dp[begin][begin+d] = 2 + dp[begin+1][begin+d-1];
                    else dp[begin][begin+d] = max(dp[begin][begin+d - 1], dp[begin+1][begin+d]);
                    maxL = max(maxL, dp[begin][begin+d]);
                }
            }
        }
        return maxL;
    }
};