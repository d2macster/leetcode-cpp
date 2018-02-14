//
// Created by Andrii Cherniak on 1/23/18.
//

#include <vector>
using std::vector;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int > >& matrix) {
        if (matrix.empty())
            return vector<int>();
        int R = matrix.size();
        int C = matrix[0].size();
        vector<int> result = vector<int>(R*C, 0);
        int r_id = 0;
        int l = 0, r = C-1, u = 0, d = R - 1;
        while (true){
            for (int c = l; c <= r; c++) result[r_id++] = matrix[u][c];
            if (++u > d) break;
            for (int row = u; row <= d; row ++) result[r_id++] = matrix[row][r];
            if (--r < l) break;
            for (int c = r; c >= l; c--) result[r_id++] = matrix[d][c];
            if (--d < u) break;
            for (int row = d; row >= u; row--) result[r_id++] = matrix[row][l];
            if (++l > r) break;
        }

        return result;
    }
};