//
// Created by Andrii Cherniak on 1/18/18.
//
#include <vector>
#include <iostream>

using std::vector;

class Solution {
public:
    int arrayPairSum(vector<int> &nums) {
        int L = nums.size();
        if (L == 0) return 0;
        if (L == 1) return nums[0];
        if (L == 2) return std::min(nums[0], nums[1]);

        std::sort(nums.begin(), nums.end());
        int sum = 0;
        for(int i = 0; i < L; i+= 2) sum += nums[i];
        return sum;
    }
};