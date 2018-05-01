//
// Created by Andrii Cherniak on 4/30/18.
//
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool checkSubarraySum(vector<int> &nums, int k) {
        int L = nums.size();
        if (L < 2)
            return false;

        unordered_map<int, int> residuals;
        residuals[0] = -1;
        int s = 0;
        for (int i = 0; i < L; i++){
            s += nums[i];
            if (k != 0) s %= k;
            if (residuals.find(s) != residuals.end()){
                if (i - residuals[s] > 1) return true;
            }
            else residuals[s] = i;
        }


        return false;

    }
};