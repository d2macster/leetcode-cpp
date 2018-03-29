//
// Created by Andrii Cherniak on 3/28/18.
//

#include <vector>
#include <queue>
#include <limits>

using namespace std;

class Solution {
public:
    int shortestDistance(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        int R = maze.size();
        if (R == 0) return true;
        int C = maze[0].size();
        if (C == 0) return true;

        vector<vector<int>> distance = vector<vector<int> >(R, vector<int>(C, INT_MAX));

        queue<vector<int>> q;
        vector<int> spot = vector<int >(2, 0);
        spot[0] = start[0];
        spot[1] = start[1];
        q.push(spot);

        vector<vector<int>> directions = vector<vector<int>>(4, vector<int>(2, 0));
        directions[0][0] = 1;
        directions[0][1] = 0;
        directions[1][0] = 0;
        directions[1][1] = 1;
        directions[2][0] = -1;
        directions[2][1] = 0;
        directions[3][0] = 0;
        directions[3][1] = -1;

        distance[start[0]][start[1]] = 0;


        while (!q.empty()) {
            vector<int> spot = q.front();
            q.pop();

            for (vector<int> &d: directions) {
                int r = spot[0] + d[0];
                int c = spot[1] + d[1];
                while (r >= 0 && c >= 0 && r < R && c < C && maze[r][c] == 0) {
                    r += d[0];
                    c += d[1];
                }
                r -= d[0];
                c -= d[1];
                int D = abs(spot[0] - r) + abs(spot[1] - c);
                if (distance[spot[0]][spot[1]] + D < distance[r][c] ) {
                    distance[r][c] = distance[spot[0]][spot[1]] + D;
                    vector<int> next_spot = vector<int>(2, 0);
                    next_spot[0] = r;
                    next_spot[1] = c;
                    q.push(next_spot);
                }
            }
        }

        return (distance[destination[0]][destination[1]] == INT_MAX)?-1:distance[destination[0]][destination[1]];

    }
};