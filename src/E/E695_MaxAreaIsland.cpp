//
// Created by Andrii Cherniak on 1/29/18.
//
#include <vector>
using std::vector;

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int > >& grid) {
        int R = grid.size();
        if (R == 0) return 0;
        int C = grid[0].size();
        if (C == 0) return 0;
        bool visited[R][C];
        for (int r = 0; r < R; r++)
            for (int c = 0; c < C; c++) visited[r][c] = false;

        int q[R*C][2];
        int begin = 0, end = 0, area, max_area = 0;
        int rr, cc;

        for (int r = 0; r < R; r++)
            for (int c = 0; c < C; c++) {
                if (grid[r][c] == 1 && !visited[r][c]){
                    q[0][0] = r;
                    q[0][1] = c;
                    begin = 0;
                    end = 1;
                    area = 0;
                    while (begin < end){
                        rr = q[begin][0];
                        cc = q[begin][1];

                        area++;

                        visited[rr][cc] = true;

                        if (rr - 1 >= 0 && grid[rr-1][cc] == 1 && !visited[rr-1][cc]) {
                            q[end][0] = rr-1;
                            q[end][1] = cc;
                            visited[rr-1][cc] = true;
                            end++;
                        }
                        if (cc - 1 >= 0 && grid[rr][cc-1] == 1 && !visited[rr][cc-1]) {
                            q[end][0] = rr;
                            q[end][1] = cc-1;
                            visited[rr][cc-1] = true;
                            end++;
                        }
                        if (rr + 1 < R && grid[rr+1][cc] == 1 && !visited[rr+1][cc]) {
                            q[end][0] = rr+1;
                            q[end][1] = cc;
                            visited[rr+1][cc] = true;
                            end++;
                        }
                        if (cc + 1 < C && grid[rr][cc+1] == 1 && !visited[rr][cc+1]) {
                            q[end][0] = rr;
                            q[end][1] = cc+1;
                            visited[rr][cc+1] = true;
                            end++;
                        }
                        begin ++;
                    }
                    max_area = std::max(max_area, area);
                }
            }

        return max_area;

    }
};