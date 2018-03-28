//
// Created by Andrii Cherniak on 3/27/18.
//
#include <vector>
#include <limits>

using namespace std;

class Solution {
    vector<pair<int, int>> flow;

    void dfs(vector<vector<int>> &matrix, vector<vector<int> > &ocean, int r, int c, int R, int C, int height,
             int ocean_type) {
        if (r < 0 || c < 0 || r >= R || c >= C ||
            (ocean[r][c] & ocean_type) == ocean_type ||
            matrix[r][c] < height)
            return;
        ocean[r][c] |= ocean_type;
        if (ocean[r][c] == 3) flow.push_back({r, c});
        dfs(matrix, ocean, r + 1, c, R, C, matrix[r][c], ocean[r][c]);
        dfs(matrix, ocean, r - 1, c, R, C, matrix[r][c], ocean[r][c]);
        dfs(matrix, ocean, r, c + 1, R, C, matrix[r][c], ocean[r][c]);
        dfs(matrix, ocean, r, c - 1, R, C, matrix[r][c], ocean[r][c]);
    }

public:
    vector<pair<int, int>> pacificAtlantic(vector<vector<int>> &matrix) {
        int R = matrix.size();
        if (R == 0) return flow;
        int C = matrix[0].size();
        if (C == 0) return flow;

        vector<vector<int> > ocean = vector<vector<int> >(R, vector<int>(C, 0));

        for (int c = 0; c < C; c++) {
            dfs(matrix, ocean, 0, c, R, C, INT_MIN, 1);
            dfs(matrix, ocean, R - 1, c, R, C, INT_MIN, 2);
        }
        for (int r = 0; r < R; r++) {
            dfs(matrix, ocean, r, 0, R, C, INT_MIN, 1);
            dfs(matrix, ocean, r, C - 1, R, C, INT_MIN, 2);
        }
        return flow;
    }
};