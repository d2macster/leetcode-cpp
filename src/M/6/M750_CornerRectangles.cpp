//
// Created by Andrii Cherniak on 4/29/18.
//
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    int countCornerRectangles(vector<vector<int>> &grid) {
        int R = grid.size();
        if (R == 0) return 0;
        int C = grid[0].size();
        if (C == 0) return 0;
        int cnt = 0;

        map<pair<int, int>, int> corners;

        for (int c1 = 0; c1 < C - 1; c1++) {
            if (grid[0][c1] == 1) {
                for (int c2 = c1 + 1; c2 < C; c2++) {
                    if (grid[0][c2] == 1){
                        pair<int , int> pp = make_pair(c1, c2);
                        corners[pp]++;
                    }
                }
            }
        }


        for (int r = 1; r < R; r++) {
            for (int c1 = 0; c1 < C - 1; c1++) {
                if (grid[r][c1] == 1) {
                    for (int c2 = c1 + 1; c2 < C; c2++) {
                        if (grid[r][c2] == 1){
                            pair<int , int> pp = make_pair(c1, c2);
                            cnt += corners[pp];
                            corners[pp]++;
                        }
                    }
                }
            }
        }
        return cnt;

    }
};