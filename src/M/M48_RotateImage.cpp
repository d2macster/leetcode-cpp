//
// Created by Andrii Cherniak on 1/22/18.
//
#include <vector>
#include <algorithm>

using std::vector;
using std::reverse;

class Solution {
public:
    void rotate(vector<vector<int > > &matrix) {
        int R = matrix.size();
        if (R <= 1) return;
        int C = matrix[0].size();
        if (C <= 1) return;
        for (int r = 0; r < R; r++){
            for (int c = r; c < C; c++)
                std::swap(matrix[r][c], matrix[c][r]);
        }
        for (int r = 0; r < R; r++)
            reverse(matrix[r].begin(), matrix[r].end());
    }
};