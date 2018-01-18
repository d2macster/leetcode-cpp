//
// Created by Andrii Cherniak on 1/18/18.
//

#include <vector>
using std::vector;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int L = prices.size();
        if (L <= 1)
            return 0;
        int profit = 0;
        for (int i = 1; i < L; i++){
            if (prices[i] > prices[i-1])
                profit += prices[i] - prices[i-1];
        }
        return profit;
    }
};