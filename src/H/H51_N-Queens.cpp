//
// Created by Andrii Cherniak on 7/2/18.
//

#include <vector>
#include <string>

using namespace std;

class Solution {
    void helper(vector<vector<string>> &result, int n, int row_id, vector<int> &row_pos, vector<string> &board) {
        if (row_id == n) {
            result.push_back(board);
            return;
        }
        for (int i = 0; i < n; i++) {
            bool ok = true;
            for(int row = 0; (row < row_id) && ok; row++)
                if (row_pos[row] == i) ok = false;
            for(int row = row_id-1, col = i-1; (row >= 0) && (col >= 0) && ok; row--,col--)
                if (row_pos[row] == col) ok = false;
            for(int row = row_id-1, col = i+1; (row >= 0) && (col < n) && ok; row--,col++)
                if (row_pos[row] == col) ok = false;
            if (ok) {
                row_pos[row_id] = i;
                board[row_id][i] = 'Q';
                helper(result, n, row_id + 1, row_pos, board);
                board[row_id][i] = '.';
            }
        }
    }

public:
    vector<vector<string>> solveNQueens(int n) {
        if (n <= 0)
            return vector<vector<string>>();

        auto result = vector<vector<string>>();
        string row = "";
        for (int i = 1; i <= n; i++) row += ".";
        vector<string> board = vector<string>(n, row);

        vector<int> row_pos = vector<int>(n, 0);

        helper(result, n, 0, row_pos, board);
        return result;
    }
};