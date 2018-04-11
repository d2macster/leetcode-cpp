//
// Created by Andrii Cherniak on 4/11/18.
//
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int maxKilledEnemies(vector<vector<char>> &grid) {
        int R = grid.size();
        if (R == 0) return 0;
        int C = grid[0].size();
        vector<vector<int>> row_segments = vector<vector<int>>(R, vector<int>(C, 0));
        vector<vector<int>> col_segments = vector<vector<int>>(R, vector<int>(C, 0));


        for (int r = 0; r < R; r++) {
            int left = 0;
            int enemies = 0;
            for (int c = 0; c < C; c++) {
                if (grid[r][c] == 'E') enemies++;
                else if (grid[r][c] == 'W') {
                    for (; left < c; left++) row_segments[r][left] = enemies;
                    left = c + 1;
                    enemies = 0;
                }
            }
            for (; left < C; left++) row_segments[r][left] = enemies;
        }
        for (int c = 0; c < C; c++){
            int top = 0;
            int enemies = 0;
            for (int r = 0; r < R; r++){
                if (grid[r][c] == 'E') enemies++;
                else if (grid[r][c] == 'W') {
                    for (; top < R; top++) col_segments[top][c] = enemies;
                    top = r + 1;
                    enemies = 0;
                }
            }
            for (; top < R; top++) col_segments[top][c] = enemies;
        }

        int to_kill = 0;

        for (int r = 0; r < R; r++) {
            for (int c = 0; c < C; c++) {
                if (grid[r][c] == '0')
                to_kill = max(to_kill, row_segments[r][c] + col_segments[r][c]);
            }
        }

        return to_kill;

    }
};