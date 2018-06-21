//
// Created by Andrii Cherniak on 6/21/18.
//
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int orderOfLargestPlusSign(int N, vector<vector<int>> &mines) {
        if (N <= 0) return 0;
        auto grid = vector<vector<int>>(N, vector<int>(N, 1));
        auto cross_r = vector<vector<int>>(N, vector<int>(N, 0));
        auto cross_c = vector<vector<int>>(N, vector<int>(N, 0));

        for(auto m: mines) grid[m[0]][m[1]] = 0;
        int answer = 0;
        vector<int> l_scan = vector<int>(N, 0);
        vector<int> r_scan = vector<int>(N, 0);
        int cnt = 0;

        for(int r = 0; r < N; r++){
            for (int i = 0; i < N; i++) {
                l_scan[i] = 0;
                r_scan[i] = 0;
            }
            cnt = 0;
            for(int i = 0; i < N; i++){
                cnt = (grid[r][i] == 1)?cnt+1:0;
                l_scan[i] = cnt;
            }
            cnt  = 0;
            for(int i = N-1; i >= 0; i--){
                cnt = (grid[r][i] == 1)?cnt+1:0;
                r_scan[i] = cnt;
            }
            for (int c = 0; c < N; c++) cross_r[r][c] = min(l_scan[c], r_scan[c]);
        }
        for(int c = 0; c < N; c++){
            for (int i = 0; i < N; i++) {
                l_scan[i] = 0;
                r_scan[i] = 0;
            }
            cnt = 0;
            for (int i = 0; i < N; i++){
                cnt = (grid[i][c] == 1)? cnt + 1:0;
                l_scan[i] = cnt;
            }
            cnt = 0;
            for (int i = N-1; i >= 0; i--){
                cnt = (grid[i][c] == 1)? cnt + 1:0;
                r_scan[i] = cnt;
            }
            for (int r = 0; r < N; r++) cross_c[r][c] = min(l_scan[r], r_scan[r]);
        }
        for (int r = 0; r < N; r++){
            for (int c = 0; c < N; c++) answer = max(answer, min(cross_r[r][c], cross_c[r][c]));
        }
        return answer;
    }
};