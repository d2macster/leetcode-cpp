//
// Created by Andrii Cherniak on 4/13/18.
//
#include <vector>
#include <iostream>

using namespace std;

class Solution {
    int iterator(vector<vector<int>> &M, int r, int c, int dr, int dc, int R, int C) {
        int maxInterval = 0;
        int count = 0;
        while (r >= 0 && c >= 0 && r < R && c < C) {
            if (M[r][c] == 1) {
                count++;
                maxInterval = max(maxInterval, count);
            } else count = 0;
            r += dr;
            c += dc;
        }
        maxInterval = max(maxInterval, count);
        return maxInterval;
    }

public:
    int longestLine(vector<vector<int>> &M) {
        int R = M.size();
        if (R == 0) return 0;
        int C = M[0].size();
        if (C == 0) return 0;
        int result = 0;
        for (int r = 0; r < R; r++) {
            result = max(result, iterator(M, r, 0, 0, 1, R, C)); // horisontal
            result = max(result, iterator(M, r, 0, 1, 1, R, C)); //diagonal
            result = max(result, iterator(M, r, C - 1, 1, -1, R, C)); //anti diagonal

        }

        for (int c = 0; c < C; c++) {
            result = max(result, iterator(M, 0, c, 1, 0, R, C)); // vertical
            result = max(result, iterator(M, 0, c, 1, 1, R, C)); // diagonal
            result = max(result, iterator(M, 0, c, 1, -1, R, C)); // anti diagonal

        }

        return result;

    }
};