//
// Created by Andrii Cherniak on 3/28/18.
//
#include <vector>

using namespace std;

const int M = 1000000000 + 7;

class Solution {
public:
    int findPaths(int m, int n, int N, int i, int j) {
        if (N == 0)
            return 0;
        vector<vector<int> > dp = vector<vector<int> >(m, vector<int>(n, 0));

        dp[i][j] = 1;
        int counter = 0;
        for (int moves = 1; moves <= N; moves++) {
            vector<vector<int> > dp_next = vector<vector<int> >(m, vector<int>(n, 0));
            for (int r = 0; r < m; r++) {
                counter = (counter + dp[r][0]) % M;
                counter = (counter + dp[r][n - 1]) % M;
            }
            for (int c = 0; c < n; c++) {
                counter = (counter + dp[0][c]) % M;
                counter = (counter + dp[m - 1][c]) % M;
            }
            for (int r = 0; r < m; r++) {
                for (int c = 0; c < n; c++) {
                    if (r > 0) dp_next[r][c] = (dp_next[r][c] + dp[r - 1][c]) % M;

                    if (c > 0)dp_next[r][c] = (dp_next[r][c] + dp[r][c - 1]) % M;
                    if (r < m - 1) dp_next[r][c] = (dp_next[r][c] + dp[r + 1][c]) % M;
                    if (c < n - 1)dp_next[r][c] = (dp_next[r][c] + dp[r][c + 1]) % M;
                }
            }
            dp = dp_next;

        }

        return counter % M;

    }
};