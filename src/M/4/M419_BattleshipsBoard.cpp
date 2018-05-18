//
// Created by Andrii Cherniak on 5/18/18.
//
#include <vector>

using namespace std;

class Solution {

public:
    int countBattleships(vector<vector<char>> &board) {
        if (board.empty()) return 0;
        int R = board.size();
        int C = board[0].size();
        int counter = 0;
        for (int r = 0; r < R; r++) {
            for (int c = 0; c < C; c++) {
                if (board[r][c] == 'X') {
                    if ((c == 0 || board[r][c - 1] == '.') && (r == 0 || board[r - 1][c] == '.')) counter++;
                }
            }
        }

        return counter;
    }
};