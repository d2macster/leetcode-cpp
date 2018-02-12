//
// Created by Andrii Cherniak on 2/12/18.
//
#include <vector>

using std::vector;

class Solution {
    void dfs(vector<vector<char> > &grid, int r, int c, int R, int C) {
        grid[r][c] = '0';
        if (r - 1 >= 0 && grid[r - 1][c] == '1') dfs(grid, r - 1, c, R, C);
        if (c - 1 >= 0 && grid[r][c - 1] == '1') dfs(grid, r, c - 1, R, C);
        if (r + 1 < R && grid[r + 1][c] == '1') dfs(grid, r + 1, c, R, C);
        if (c + 1 < C && grid[r][c + 1] == '1') dfs(grid, r, c + 1, R, C);
    }

public:

    int numIslands(vector<vector<char> > &grid) {
        int R = grid.size();
        if (R == 0)
            return 0;
        int C = grid[0].size();
        if (C == 0) return 0;

        int counter = 0;

        for (int r = 0; r < R; r++)
            for (int c = 0; c < C; c++)
                if (grid[r][c] == '1') {
                    counter++;
                    dfs(grid, r, c, R, C);
                }
        return counter;
    }
};