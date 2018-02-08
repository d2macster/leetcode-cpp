//
// Created by Andrii Cherniak on 2/7/18.
//
#include <vector>

using std::vector;

class Solution {
public:
    bool isValidSudoku(vector<vector<char> > &board) {
        int check_rows[9][9] = {0};
        int check_cols[9][9] = {0};
        int check_boxes[9][9] = {0};

        int digit, block_r, block_c, block_id;
        for (int r = 0; r < 9; r++)
            for (int c = 0; c < 9; c++)
                if (board[r][c] != '.'){
                    digit = board[r][c] - '0' - 1;
                    block_r = r / 3;
                    block_c = c / 3;
                    block_id = block_r * 3 + block_c;
                    if (check_rows[r][digit] == 1) return false;
                    if (check_cols[c][digit] == 1) return false;
                    if (check_boxes[block_id][digit] == 1)
                        return false;
                    check_rows[r][digit] = 1;
                    check_cols[c][digit] = 1;
                    check_boxes[block_id][digit] = 1;
                }


        return true;
    }
};