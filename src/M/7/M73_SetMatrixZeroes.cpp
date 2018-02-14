//
// Created by Andrii Cherniak on 1/31/18.
//
#include <vector>
using std::vector;

class Solution {
public:
    void setZeroes(vector<vector<int > >& matrix) {
        int R = matrix.size();
        if (R == 0) return;
        int C = matrix[0].size();
        if (C == 0) return;
        bool cols[C];
        for (int i = 0; i < C; i++) cols[i] = false;

        bool isSet = false;

        for (int r = 0; r < R; r++){
            isSet = false;
            for (int c = 0; c < C; c++)
                if (matrix[r][c] == 0) {
                    cols[c] = true;
                    isSet = true;
                }
            if (isSet){
                for (int c = 0; c < C; c++) matrix[r][c] = 0;
            }
        }

        for (int c = 0; c < C; c++){
            if (cols[c]) {
                for (int r = 0; r < R; r++) matrix[r][c] = 0;
            }
        }
    }
};