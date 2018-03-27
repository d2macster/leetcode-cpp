//
// Created by Andrii Cherniak on 3/26/18.
//
#include <vector>
#include <iostream>

using namespace std;

class Solution {
    void propagate(vector<vector<char> > &board, int R, int C, int r, int c) {
        if (r < 0 || r >= R || c < 0 || c >= C || board[r][c] == 'X' || board[r][c] == 'S') return;

        board[r][c] = 'S';
        propagate(board, R, C, r + 1, c);
        propagate(board, R, C, r, c + 1);
        propagate(board, R, C, r - 1, c);
        propagate(board, R, C, r, c - 1);
    }

public:
    void solve(vector<vector<char> > &board) {
        int R = board.size();
        if (R == 0)
            return;
        int C = board[0].size();
        if (C == 0) return;

        for (int r = 0; r < R; r++) {
            if (board[r][0] == 'O') propagate(board, R, C, r, 0);
            if (board[r][C - 1] == 'O') propagate(board, R, C, r, C - 1);
        }
        for (int c = 0; c < C; c++) {
            if (board[0][c] == 'O') propagate(board, R, C, 0, c);
            if (board[R - 1][c] == 'O') propagate(board, R, C, R - 1, c);
        }

        for (int r = 0; r < R; r++) {
            for (int c = 0; c < C; c++) {
                if (board[r][c] == 'O') board[r][c] = 'X';
                if (board[r][c] == 'S') board[r][c] = 'O';
            }
        }

    }
};