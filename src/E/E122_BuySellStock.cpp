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
        int pb0 = -prices[0], pb1, ps0 = 0, ps1;
        for (int i = 1; i < L; i++){
            pb1 = std::max(pb0, ps0 - prices[i]);
            ps1 = std::max(ps0, pb0 + prices[i]);
            pb0 = pb1;
            ps0 = ps1;
        }
        return std::max(pb0, ps0);
    }
};