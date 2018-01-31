//
// Created by Andrii Cherniak on 1/12/18.
//
#include <vector>
using std::vector;

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int result = 0;
        int L = prices.size();
        if (L <= 1) return 0;
        int start = prices[0];
        int profit = 0;
        for (int i = 1; i < L; i++){
            profit = prices[i] - start;
            result = profit > result ? profit : result;
            start = prices[i] < start ? prices[i] : start;
        }
        return result;
    }
};