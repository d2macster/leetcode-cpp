//
// Created by Andrii Cherniak on 4/14/18.
//
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int getMoneyAmount(int n) {
        if (n <= 1) return 0;
        vector<vector<int>> DP = vector<vector<int>>(n + 1, vector<int>(n + 1, n * n));
        for (int i = 1; i <= n; i++)DP[i][i] = 0;
        for(int d = 1; d < n; d++)
        {
            for (int left = 1; left <= n; left++){
                int right = left + d;
                if (right <= n) {
                    int cost = 9999999;
                    for (int k = left; k <= right; k++) {
                        int lv = (k - 1 >= left) ? DP[left][k - 1] : 0;
                        int rv = (k + 1 <= right) ? DP[k + 1][right] : 0;
                        cost = min(cost, k + max(lv, rv));
                    }
                    DP[left][right] = cost;
                }
            }
        }

        return DP[1][n];
    }
};