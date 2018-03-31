//
// Created by Andrii Cherniak on 3/30/18.
//
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int> &prices, int fee) {
        int L = prices.size();
        if (L <= 1)
            return 0;
        int cash = 0;
        int stock = -prices[0];
        int next_cash, next_stock;
        for (int i = 1; i < L; i++){
            next_cash = max(cash, prices[i] + stock - fee);
            next_stock = max(stock, cash - prices[i]);
            cash = next_cash;
            stock = next_stock;
        }
        return cash;
    }
};