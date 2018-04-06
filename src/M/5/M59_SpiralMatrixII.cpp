//
// Created by Andrii Cherniak on 4/5/18.
//
#include <vector>

using namespace std;


class Solution {
    vector<pair<int, int>> moves;

    bool canMove(int n, vector<vector<int>> &M, int move_id, int r, int c) {
        r += moves[move_id].first;
        c += moves[move_id].second;

        if (r < 0 || c < 0 || r >= n || c >= n || M[r][c] != 0) return false;
        return true;
    }

public:
    vector<vector<int>> generateMatrix(int n) {
        if (n <= 0)
            return vector<vector<int>>();
        vector<vector<int>> M = vector<vector<int>>(n, vector<int>(n, 0));
        moves.push_back(make_pair(0, 1));
        moves.push_back(make_pair(1, 0));
        moves.push_back(make_pair(0, -1));
        moves.push_back(make_pair(-1, 0));

        int r = 0, c = 0;
        int move_id = 0;

        for (int i = 1; i <= n * n; i++) {
            M[r][c] = i;
            if (!canMove(n, M, move_id, r, c)) move_id = (move_id + 1) % 4;
            r += moves[move_id].first;
            c += moves[move_id].second;
        }
        return M;
    }
};