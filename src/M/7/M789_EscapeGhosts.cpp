//
// Created by Andrii Cherniak on 4/12/18.
//
#include <vector>

using namespace std;

class Solution {
    int distance(int x1, int y1, int x2, int y2) {
        return abs(x1 - x2) + abs(y1 - y2);
    }

public:
    bool escapeGhosts(vector<vector<int>> &ghosts, vector<int> &target) {
        int gL = ghosts.size();
        if (gL == 0) return true;
        int dEscape = distance(0, 0, target[0], target[1]);
        for (int i = 0; i < gL; i++) {
            int dGhost = distance(ghosts[i][0], ghosts[i][1], target[0], target[1]);
            if (dGhost <= dEscape) return false;
        }
        return true;
    }
};