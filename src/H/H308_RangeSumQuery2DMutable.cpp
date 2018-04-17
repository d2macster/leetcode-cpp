//
// Created by Andrii Cherniak on 4/17/18.
//
#include <vector>
#include <iostream>
using namespace std;

class NumMatrix {
    vector<vector<int>> M;
    vector<vector<int>> S;
    void rowSum(int row){
        int s = 0;
        for (int c = 0; c < M[row].size(); c++){
            s += M[row][c];
            S[row][c] = s;
        }
    }
public:
    NumMatrix(vector<vector<int>> matrix) {
        M = matrix;
        S = matrix;
        for (int r = 0; r < M.size(); r++) rowSum(r);
    }

    void update(int row, int col, int val) {
        M[row][col] = val;
        rowSum(row);
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        int s = 0;
        for (int r = row1; r <= row2; r++){
            s += (S[r][col2] - S[r][col1] + M[r][col1]);
        }
        return s;
    }
};