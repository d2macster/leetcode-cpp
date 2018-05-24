//
// Created by Andrii Cherniak on 5/23/18.
//
#include <vector>

using namespace std;

class Solution {
    int overlap(vector<vector<int>> &A, vector<vector<int>> &B, int R, int C, int dr, int dc) {
        int result = 0;
        for (int r = 0; r < R; r++){
            int rB = r + dr;
            if (rB >= 0 && rB < R) {
                for (int c = 0; c < C; c++) {
                    int cB = c + dc;
                    if (cB >= 0 && cB < C) result += (A[r][c] == 1 && A[r][c] == B[rB][cB]);
                }
            }
        }
        return result;
    }

public:
    int largestOverlap(vector<vector<int>> &A, vector<vector<int>> &B) {
        int result = 0;
        if (A.empty()) return 0;
        int R = A.size();
        int C = A[0].size();
        for (int dr = -R; dr <= R; dr++){
            for (int dc = -C; dc <= C; dc++){
                int o = overlap(A, B, R, C, dr, dc);
                result = max(result, o);
            }
        }
        return result;
    }
};