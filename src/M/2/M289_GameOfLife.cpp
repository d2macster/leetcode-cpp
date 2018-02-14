//
// Created by Andrii Cherniak on 1/31/18.
//
#include <vector>

using std::vector;
using std::min;
using std::max;

class Solution {
public:
    void gameOfLife(vector<vector<int> > &board) {
        int R = board.size();
        if (R == 0) return;
        int C = board[0].size();
        if (C == 0) return;

        int r, c, rr, cc, counter, next;

        for (r = 0; r < R; r++) {
            for (c = 0; c < C; c++) {
                counter = 0;
                for (rr = max(0, r - 1); rr <= min(r + 1, R - 1); rr++)
                    for (cc = max(0, c - 1); cc <= min(c + 1, C - 1); cc++)
                        if (rr != r || cc != c)
                        counter += (board[rr][cc] & 1);
                if ((counter == 3) || (counter == 2 && board[r][c])) board[r][c] |= 2;
            }
        }

        for (r = 0; r < R; r++)
            for (c = 0; c < C; c++)
                board[r][c] >>= 1;
    }
};