//
// Created by Andrii Cherniak on 6/21/18.
//
#include <vector>
#include <limits>
using namespace std;

class Solution {
public:
    int minCostII(vector<vector<int>>& costs) {
        int n = costs.size();
        if (n == 0) return 0;
        int k = costs[0].size();
        if (k == 1)
            return costs[0][0];
        
        vector<int> prev_cost = vector<int>(k, 0);
        vector<int> next_cost = vector<int>(k, 0);

        for (int i = 0; i < n; i++){
            for(int j = 0; j < k; j++){
                next_cost[j] = INT_MAX;
                for(int l = 0; l < k; l++){
                    if (l != j) next_cost[j] = min(next_cost[j], prev_cost[l] + costs[i][l]);
                }
            }
            prev_cost = next_cost;
        }
        int answer = next_cost[0];
        for (int i = 1; i < k; i++) answer = min(answer, next_cost[i]);
        return answer;
    }
};