//
// Created by Andrii Cherniak on 4/11/18.
//
#include <vector>

using namespace std;

class Solution {
public:
    int maxA(int N) {
        vector<vector<int>> dp = vector<vector<int>> (N+1, vector<int>(3, 0));
        for (int i = 1; i <= N; i++){
            dp[i][1] = (i >= 2)?dp[i-2][0]:0;
            int cv1 = 2*dp[i-1][1];
            int cv2 = (i >= 2)?3*dp[i-2][1]:0;
            int cv3 = (i >= 3)?4*dp[i-3][1]:0;

            dp[i][2] = max(cv3, max(cv1, cv2));
            dp[i][0] = max(dp[i-1][0] + 1, dp[i][2]);
        }

        return dp[N][0];
    }
};