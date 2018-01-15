//
// Created by Andrii Cherniak on 1/15/18.
//

#include <vector>

using std::vector;

class Solution {
public:
    int minCost(vector<vector<int > > &costs) {
        int L = costs.size();
        if (L == 0)
            return 0;
        int cost[L][3];
        cost[0][0] = costs[0][0];
        cost[0][1] = costs[0][1];
        cost[0][2] = costs[0][2];

        for (int i = 1; i < L; i++){
            cost[i][0] = std::min(cost[i-1][1], cost[i-1][2]) + costs[i][0];
            cost[i][1] = std::min(cost[i-1][0], cost[i-1][2]) + costs[i][1];
            cost[i][2] = std::min(cost[i-1][0], cost[i-1][1]) + costs[i][2];
        }
        return std::min(std::min(cost[L-1][0], cost[L-1][1]), cost[L-1][2]);

    }
};