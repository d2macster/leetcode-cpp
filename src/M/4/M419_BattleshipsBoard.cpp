//
// Created by Andrii Cherniak on 5/18/18.
//
#include <vector>

using namespace std;

class Solution {
    void removeShip(vector<vector<char>> &board, int r, int c, int R, int C) {
        for (int i = c; i < C && board[r][i] == 'X'; i++) board[r][i] = '.';
        for (int i = r+1; i < R && board[i][c] == 'X'; i++) board[i][c] = '.';
    }

public:
    int countBattleships(vector<vector<char>> &board) {
        if (board.empty()) return 0;
        int R = board.size();
        int C = board[0].size();
        int counter = 0;
        for (int r = 0; r < R; r++) {
            for (int c = 0; c < C; c++) {
                if (board[r][c] == 'X') {
                    counter++;
                    removeShip(board, r, c, R, C);
                }
            }
        }

        return counter;
    }
};