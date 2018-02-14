//
// Created by Andrii Cherniak on 1/17/18.
//
#include <vector>

using std::vector;
using std::min;
using std::max;


class Solution {
public:
    int maximalSquare(vector<vector<char> > &matrix) {
        int R = matrix.size();
        if (R == 0) return 0;
        int C = matrix[0].size();
        if (C == 0) return 0;

        int dp[R][C];
        for (int r = 0; r < R; r++) {
            for (int c = 0; c < C; c++) dp[r][c] = 0;
        }
        int msq = 0;
        for (int r = 0; r < R; r++) {
            if (matrix[r][0] == '1') {
                dp[r][0] = 1;
                msq = 1;
            }
        }
        for (int c = 0; c < C; c++) {
            if (matrix[0][c] == '1') {
                dp[0][c] = 1;
                msq = 1;
            }
        }
        for (int r = 1; r < R; r++) {
            for (int c = 1; c < C; c++) {
                if (matrix[r][c] == '1') {
                    dp[r][c] = min(min(dp[r][c-1], dp[r-1][c]), dp[r-1][c-1]) + 1;
                    msq = max(msq, dp[r][c]);
                }
            }
        }

        return msq * msq;
    }
};