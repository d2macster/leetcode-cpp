//
// Created by Andrii Cherniak on 1/15/18.
//
#include <vector>
#include <iostream>

using std::vector;

class Solution {
public:
    int minPathSum(vector<vector<int> > &grid) {
        int R = grid.size();
        if (R == 0)
            return 0;
        int C = grid[0].size();
        if (C == 0)
            return 0;
        int path[C];
        path[0] = grid[0][0];
        for (int c = 1; c < C; c++) {
            path[c] = path[c - 1] + grid[0][c];
        }

        for (int r = 1; r < R; r++) {
            path[0] += grid[r][0];
            for (int c = 1; c < C; c++)
                path[c] = std::min(path[c], path[c - 1]) + grid[r][c];
        }

        return path[C - 1];
    }
};