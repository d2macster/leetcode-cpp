//
// Created by Andrii Cherniak on 3/29/18.
//
#include <vector>
#include <unordered_set>
#include <string>
#include <iostream>

using namespace std;

class Solution {
    void
    explore(vector<vector<int> > &grid, vector<vector<bool> > &visited, int r, int c, int R, int C, char direction,
            string &signature) {
        if (r < 0 || c < 0 || r >= R || c >= C || visited[r][c] || grid[r][c] == 0) return;
        visited[r][c] = true;
        signature += direction;
        explore(grid, visited, r + 1, c, R, C, '1', signature);
        explore(grid, visited, r - 1, c, R, C, '2', signature);
        explore(grid, visited, r, c + 1, R, C, '3', signature);
        explore(grid, visited, r, c - 1, R, C, '4', signature);
        signature += '0';
    }

public:
    int numDistinctIslands(vector<vector<int> > &grid) {
        int R = grid.size();
        if (R == 0) return 0;
        int C = grid[0].size();
        if (C == 0) return 0;
        vector<vector<bool> > visited = vector<vector<bool> >(R, vector<bool>(C, false));
        unordered_set<string> islands;

        for (int r = 0; r < R; r++)
            for (int c = 0; c < C; c++) {
                if (grid[r][c] == 1 && !visited[r][c]) {
                    string signature = "";
                    explore(grid, visited, r, c, R, C, '0', signature);

                    islands.insert(signature);
                }
            }

        return islands.size();
    }
};