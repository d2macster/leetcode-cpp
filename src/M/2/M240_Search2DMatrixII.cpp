//
// Created by Andrii Cherniak on 4/13/18.
//
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target) {
        int R = matrix.size();
        if (R == 0) return false;
        int C = matrix[0].size();
        if (C == 0) return false;

        if (target < matrix[0][0] || target > matrix[R - 1][C - 1]) return false;
        int lo = 0, hi = R - 1;
        int row_begin = 0;
        while (lo < hi) {
            int mid = (lo + hi) / 2;
            if (target == matrix[mid][0] || target == matrix[mid][C - 1]) return true;
            else if (target > matrix[mid][C - 1]) lo = mid + 1;
            else hi = mid - 1;
        }
        if (target >= matrix[lo][0]) row_begin = lo;
        else row_begin = hi;
        for (int r = row_begin; r < R; r++) {
            if (target >= matrix[r][0] && target <= matrix[r][C - 1]) {
                if (binary_search(matrix[r].begin(), matrix[r].end(), target)) return true;
            }
        }
        return false;
    }
};