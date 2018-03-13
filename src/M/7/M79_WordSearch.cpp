//
// Created by Andrii Cherniak on 3/12/18.
//
#include <vector>
#include <string>

using namespace std;

class Solution {
    bool check(vector<vector<char> > &board, int r, int c, string &word, int w_id) {
        if (w_id == word.length()) return true;
        if (r < 0 || c < 0 || r >= board.size() || c >= board[0].size()) return false;
        if (board[r][c] == '*' || board[r][c] != word[w_id]) return false;
        char curC = board[r][c];
        board[r][c] = '*';
        bool exists = check(board, r + 1, c, word, w_id + 1) ||
                      check(board, r, c + 1, word, w_id + 1) ||
                      check(board, r - 1, c, word, w_id + 1) ||
                      check(board, r, c - 1, word, w_id + 1);

        board[r][c] = curC;
        return exists;
    }

public:
    bool exist(vector<vector<char> > &board, string word) {
        int L = word.size();
        for (int r = 0; r < board.size(); r++)
            for (int c = 0; c < board[0].size(); c++) {
                if (check(board, r, c, word, 0)) return true;
            }
        return false;
    }
};