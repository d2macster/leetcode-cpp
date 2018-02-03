//
// Created by Andrii Cherniak on 2/2/18.
//
#include <vector>

using std::vector;

class Solution {
public:
    int islandPerimeter(vector<vector<int> > &grid) {
        int R = grid.size();
        if (R == 0) return 0;
        int C = grid[0].size();
        if (C == 0) return 0;
        int ones = 0, neighbours = 0;

        for (int r = 0; r < R; r++)
            for (int c = 0; c < C; c++) {
                if (grid[r][c] == 1) {
                    ones++;
                    if (r > 0 && grid[r-1][c] == 1) neighbours++;
                    if (c > 0 && grid[r][c-1] == 1) neighbours++;
                }
            }
        return 4*ones - 2 * neighbours;
    }
};