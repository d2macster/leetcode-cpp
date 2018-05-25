//
// Created by Andrii Cherniak on 5/25/18.
//
#include <vector>
#include <limits>
using namespace std;

class Solution {
public:
    int minSwap(vector<int>& A, vector<int>& B) {
        int L = A.size();
        if (L == 0)
            return 0;
        vector<vector<int>> dp = vector<vector<int>>(L, vector<int>(2, INT_MAX));
        dp[L-1][0] = 0;
        dp[L-1][1] = 1;

        for (int i = L-2; i >= 0; i--){
            if (A[i] < A[i+1] && B[i] < B[i+1]) {
                dp[i][0] = min(dp[i][0], dp[i+1][0]);
                dp[i][1] = min(dp[i][1], dp[i+1][1] + 1);
            }
            if (A[i] < B[i+1] && B[i] < A[i+1]) {
                dp[i][0] = min(dp[i][0], dp[i+1][1]);
                dp[i][1] = min(dp[i][1], dp[i+1][0] + 1);
            }
        }

        return min(dp[0][0], dp[0][1]);
    }
};