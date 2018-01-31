//
// Created by Andrii Cherniak on 1/29/18.
//
#include <vector>

using std::vector;

class Solution {
public:
    int maximumProduct(vector<int> &nums) {
        int L = nums.size();
        std::sort(nums.begin(), nums.end());
        int r1 = nums[L-1] * nums[L-2] * nums[L-3];
        int r2 = nums[0] * nums[1] * nums[L-1];
        return std::max(r1, r2);
    }
};