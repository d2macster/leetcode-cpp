//
// Created by Andrii Cherniak on 3/28/18.
//
#include <vector>
#include <limits>
#include <iostream>
using namespace std;

class Solution {
    int bestPrice = INT_MAX;
    void helper(vector<int>& price, vector<vector<int>>& special, vector<int> needs, int offer_id, int cur_sum){
        int L = price.size();
        if (offer_id == special.size()){
            for (int  i = 0; i < L; i++) cur_sum += price[i] * needs[i];
            bestPrice = min(bestPrice, cur_sum);
            return;
        }
        helper(price, special, needs, offer_id+1, cur_sum);
        vector<int> offer = special[offer_id];
        while (true) {
            for (int i = 0; i < L; i++) if (needs[i] - offer[i] < 0) return;
            for (int i = 0; i < L; i++) needs[i] -= offer[i];
            cur_sum += offer[L];
            helper(price, special, needs, offer_id+1, cur_sum);
        }
    }
public:
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        helper(price, special, needs, 0, 0);
        return bestPrice;
    }
};