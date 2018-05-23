//
// Created by Andrii Cherniak on 5/23/18.
//
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>> &A) {
        if (A.empty()) return A;
        int R = A.size();
        int C = A[0].size();
        for (int r = 0; r < R; r++){
            for (int c = 0; c < C; c++) A[r][c] = 1 - A[r][c];
            reverse(A[r].begin(), A[r].end());
        }
        return A;
    }
};