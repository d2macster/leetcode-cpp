//
// Created by Andrii Cherniak on 3/27/18.
//
#include <vector>

using namespace std;
const int D = 20000;

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>> &matrix) {
        int R = matrix.size();
        if (R == 0) return matrix;
        int C = matrix[0].size();
        if (C == 0) return matrix;

        vector<vector<int>> d = vector<vector<int>>(R, vector<int>(C, D));

        for (int r = 0; r < R; r++)
            for (int c = 0; c < C; c++) {
                if (matrix[r][c] == 0) d[r][c] = 0;
                else {
                    if (r > 0) d[r][c] = min(d[r][c], d[r - 1][c] + 1);
                    if (c > 0) d[r][c] = min(d[r][c], d[r][c - 1] + 1);
                }
            }
        for (int r = R - 1; r >= 0; r--)
            for (int c = C - 1; c >= 0; c--) {
                if (matrix[r][c] == 0) d[r][c] = 0;
                else {
                    if (r < R - 1) d[r][c] = min(d[r][c], d[r + 1][c] + 1);
                    if (c < C - 1) d[r][c] = min(d[r][c], d[r][c + 1] + 1);
                }
            }

        return d;
    }
};