//
// Created by Andrii Cherniak on 1/31/18.
//
#include <vector>

using std::vector;

class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int> > &matrix) {
        int R = matrix.size();
        if (R == 0) return true;
        int C = matrix[0].size();
        if (C == 0) return false;
        for (int r = 1; r < R; r++) {
            for (int c = 1; c < C; c++)
            if (matrix[r][c] != matrix[r-1][c-1])
                return false;
        }
        return true;
    }
};