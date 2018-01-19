//
// Created by Andrii Cherniak on 1/18/18.
//
#include <vector>
#include <algorithm>
using std::vector;
using std::reverse;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int L = nums.size();
        if (L <= 1 || k == 0) return;
        k %= L;
        std::reverse(nums.begin(), nums.end());
        std::reverse(nums.begin(), nums.begin() + k);
        std::reverse(nums.begin() + k, nums.end());

    }
};