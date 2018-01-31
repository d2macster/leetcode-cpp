//
// Created by Andrii Cherniak on 1/30/18.
//
#include <vector>
using std::vector;

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int L = nums.size();
        if (L == 0) return -1;

        int l = 0, r = 0;
        for (int i = 0; i < L; i++) r += nums[i];
        for (int i = 0; i < L; i++){
            r -= nums[i];
            l = l + ((i == 0)? 0: nums[i-1]);
            if (l == r) return i;
        }
        return -1;
    }
};