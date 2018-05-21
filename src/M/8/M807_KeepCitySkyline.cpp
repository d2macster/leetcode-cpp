//
// Created by Andrii Cherniak on 5/21/18.
//
#include <vector>

using namespace std;

class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>> &grid) {
        if (grid.empty()) return 0;
        int R = grid.size();
        int C = grid[0].size();
        vector<int> left = vector<int>(R, 0);
        vector<int> top = vector<int>(C, 0);

        int result = 0;
        for (int r = 0; r < R; r++) {
            for (int c = 0; c < C; c++) left[r] = max(left[r], grid[r][c]);
        }
        for (int c = 0; c < C; c++) {
            for (int r = 0; r < R; r++) top[c] = max(top[c], grid[r][c]);
        }
        for (int r = 0; r < R; r++)
            for (int c = 0; c < C; c++)
                result += min(left[r], top[c]) - grid[r][c];

        return result;
    }
};