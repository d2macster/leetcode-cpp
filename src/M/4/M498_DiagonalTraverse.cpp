//
// Created by Andrii Cherniak on 4/11/18.
//
#include <vector>

using namespace std;

class Solution {

public:
    vector<int> findDiagonalOrder(vector<vector<int>> &matrix) {
        int R = matrix.size();
        if (R == 0) return vector<int>();
        int C = matrix[0].size();
        vector<int> order = vector<int>(R * C, 0);
        vector<vector<int>> diagonals = vector<vector<int>>(R + C - 1, vector<int>());
        for (int d = 1; d <= R + C - 1; d++) {
            int r = (d <= R) ? d - 1 : R - 1;
            int c = (d <= R) ? 0 : d - R;
            while (r >= 0 && c < C) diagonals[d - 1].push_back(matrix[r--][c++]);
        }
        int order_id = 0;

        for (int d = 1; d <= R + C - 1; d++) {
            if (d % 2 == 0) reverse(diagonals[d - 1].begin(), diagonals[d - 1].end());
            for (int v: diagonals[d - 1])
                order[order_id++] = v;
        }

        return order;
    }
};