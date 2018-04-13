//
// Created by Andrii Cherniak on 4/13/18.
//
#include <vector>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target) {
        int R = matrix.size();
        if (R == 0) return false;
        int C = matrix[0].size();
        if (C == 0) return false;

        if (target < matrix[0][0] || target > matrix[R - 1][C - 1]) return false;
        int r = R - 1, c = 0;
        while (r >= 0 && c < C){
            if (matrix[r][c] == target) return true;
            else if (target < matrix[r][c]) r--;
            else c++;
        }
        return false;
    }
};