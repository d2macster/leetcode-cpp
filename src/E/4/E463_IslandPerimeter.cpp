//
// Created by Andrii Cherniak on 2/2/18.
//
#include <vector>

using std::vector;

class Solution {
public:
    int islandPerimeter(vector<vector<int> > &grid) {
        int perimeter = 0;
        int R = grid.size();
        if (R == 0) return 0;
        int C = grid[0].size();
        if (C == 0) return 0;

        for (int r = 0; r < R; r++)
            for (int c = 0; c < C; c++) {
                if (grid[r][c] == 1) {

                    if (r == 0) perimeter++;
                    if (r == (R - 1)) perimeter++;
                    if (r > 0 && grid[r - 1][c] == 0) perimeter++;
                    if (r < (R - 1) && grid[r + 1][c] == 0) perimeter++;

                    if (c == 0) perimeter++;
                    if (c == (C - 1)) perimeter++;
                    if (c > 0 && grid[r][c - 1] == 0) perimeter++;
                    if (c < (C - 1) && grid[r][c + 1] == 0) perimeter++;
                }
            }
        return perimeter;
    }
};