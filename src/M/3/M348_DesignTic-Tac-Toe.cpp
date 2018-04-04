//
// Created by Andrii Cherniak on 4/3/18.
//
#include <vector>
#include <iostream>

using namespace std;


class TicTacToe {
    vector<int> rows, cols;
    int diagonal = 0, anti_diagonal = 0;
    int N;
public:
    TicTacToe(int n) {
        N = n;
        rows = vector<int>(n, 0);
        cols = vector<int>(n, 0);
    }

    /** Player {player} makes a move at ({row}, {col}).
        @param row The row of the board.
        @param col The column of the board.
        @param player The player, can be either 1 or 2.
        @return The current winning condition, can be either:
                0: No one wins.
                1: Player 1 wins.
                2: Player 2 wins. */
    int move(int row, int col, int player) {
        int v = (player == 1) ? 1 : -1;
        rows[row] += v;
        cols[col] += v;
        if (row == col) diagonal += v;
        if (row == N - col - 1) anti_diagonal += v;
        if (abs(rows[row]) == N || abs(cols[col]) == N || abs(diagonal) == N || abs(anti_diagonal) == N) return player;
        return 0;
    }
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe obj = new TicTacToe(n);
 * int param_1 = obj.move(row,col,player);
 */