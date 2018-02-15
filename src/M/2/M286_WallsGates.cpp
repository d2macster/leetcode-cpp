//
// Created by Andrii Cherniak on 2/14/18.
//
#include <vector>

using std::vector;

class Solution {
    void dfs(vector<vector<int> > &rooms, int r, int c, int d, int R, int C) {
        if (r >= 0 && r < R && c >= 0 && c < C && d < rooms[r][c]) {
            rooms[r][c] = d;
            dfs(rooms, r - 1, c, d + 1, R, C);
            dfs(rooms, r + 1, c, d + 1, R, C);
            dfs(rooms, r, c - 1, d + 1, R, C);
            dfs(rooms, r, c + 1, d + 1, R, C);
        }
    }

public:
    void wallsAndGates(vector<vector<int> > &rooms) {
        int R = rooms.size();
        if (R == 0)
            return;
        int C = rooms[0].size();
        if (C == 0) return;
        for (int r = 0; r < R; r++)
            for (int c = 0; c < C; c++)
                if (rooms[r][c] == 0) {
                    dfs(rooms, r - 1, c, 1, R, C);
                    dfs(rooms, r + 1, c, 1, R, C);
                    dfs(rooms, r, c - 1, 1, R, C);
                    dfs(rooms, r, c + 1, 1, R, C);
                }
    }
};