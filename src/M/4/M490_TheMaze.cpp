//
// Created by Andrii Cherniak on 3/28/18.
//
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    bool hasPath(vector<vector<int>> &maze, vector<int> &start, vector<int> &destination) {
        int R = maze.size();
        if (R == 0) return true;
        int C = maze[0].size();
        if (C == 0) return true;

        vector<vector<bool>> visited = vector<vector<bool> >(R, vector<bool>(C, false));
        queue<vector<int>> q;
        q.push(start);

        vector<vector<int>> directions = vector<vector<int>>(4, vector<int>(2, 0));
        directions[0][0] = 1;
        directions[0][1] = 0;
        directions[1][0] = 0;
        directions[1][1] = 1;
        directions[2][0] = -1;
        directions[2][1] = 0;
        directions[3][0] = 0;
        directions[3][1] = -1;

        visited[start[0]][start[1]] = true;


        while (!q.empty()) {
            vector<int> spot = q.front();
            if (spot == destination)
                return true;
            q.pop();
            visited[spot[0]][spot[1]] = true;

            for (vector<int> &d: directions) {
                int r = spot[0] + d[0];
                int c = spot[1] + d[1];
                while (r >= 0 && c >= 0 && r < R && c < C && maze[r][c] == 0) {
                    r += d[0];
                    c += d[1];
                }
                r -= d[0];
                c -= d[1];
                if (!visited[r][c]) {
                    visited[r][c] = true;
                    vector<int> next_spot = vector<int>(2, 0);
                    next_spot[0] = r;
                    next_spot[1] = c;
                    q.push(next_spot);
                }
            }
        }

        return false;

    }
};