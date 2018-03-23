//
// Created by Andrii Cherniak on 3/23/18.
//
#include <vector>
#include <queue>
#include <limits>
#include <iostream>

using namespace std;

struct min_val {
    int row;
    int col;
    int val;
};

struct comparator {
    bool operator()(const min_val &mv1, const min_val &mv2) {
        return mv1.val > mv2.val;
    }
};

class Solution {
public:
    int kthSmallest(vector<vector<int> > &matrix, int k) {
        int R = matrix.size();
        int C = matrix[0].size();

        priority_queue<min_val, vector<min_val>, comparator> q;
        for(int r = 0; r < R; r++){
            min_val mv = {r, 0, matrix[r][0]};
            q.push(mv);
        }

        int result = matrix[0][0];

        for (int el_id = 1; el_id <= k; el_id++){
            min_val mv = q.top();
            q.pop();
            result = mv.val;
            min_val next_mv = {mv.row, mv.col + 1, (mv.col + 1 < C)? matrix[mv.row][mv.col+1]:INT_MAX};
            q.push(next_mv);
        }

        return result;

    }
};