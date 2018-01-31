//
// Created by Andrii Cherniak on 1/15/18.
//

#include <vector>

using std::vector;

class Solution {
public:
    int minCostClimbingStairs(vector<int> &cost) {
        int L = cost.size();
        if (L == 0) return 0;
        if (L == 1) return cost[0];
        int dp0 = cost[0];
        int dp1 = cost[1];
        int dp11;

        for (int i = 2; i < L; i++) {
            dp11 = std::min(dp1, dp0) + cost[i];
            dp0 = dp1;
            dp1 = dp11;
        }
        return std::min(dp0, dp1);
    }
};