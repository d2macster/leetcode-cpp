//
// Created by Andrii Cherniak on 4/11/18.
//
#include <vector>

using namespace std;

class Solution {
    int DFS(vector<bool> &visited, vector<vector<int>> &skip, int cur, int remain) {
        if (remain < 0) return 0;
        else if (remain == 0) return 1;
        int result = 0;
        visited[cur] = true;
        for(int i = 1; i <= 9; i++){
            if (!visited[i] && (skip[cur][i] == 0 || visited[skip[cur][i]])){
                result += DFS(visited, skip, i, remain-1);
            }
        }
        visited[cur] = false;
        return result;
    }

public:
    int numberOfPatterns(int m, int n) {
        vector<vector<int>> skip = vector<vector<int>>(10, vector<int>(10, 0));
        skip[1][3] = 2;
        skip[3][1] = 2;
        skip[1][7] = 4;
        skip[7][1] = 4;
        skip[3][9] = 6;
        skip[9][3] = 6;
        skip[7][9] = 8;
        skip[9][7] = 8;
        skip[2][8] = 5;
        skip[8][2] = 5;
        skip[4][6] = 5;
        skip[6][4] = 5;
        skip[1][9] = 5;
        skip[9][1] = 5;
        skip[3][7] = 5;
        skip[7][3] = 5;
        vector<bool> visited = vector<bool>(10, false);
        int result = 0;
        for (int l = m; l <= n; l++) {
            for (int key = 1; key <= 9; key++) {
                result += DFS(visited, skip, key, l - 1);
            }
        }
        return result;
    }
};