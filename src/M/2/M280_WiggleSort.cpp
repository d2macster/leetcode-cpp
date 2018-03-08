//
// Created by Andrii Cherniak on 3/8/18.
//
#include <vector>
#include <algorithm>
using std::vector;

class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int L = nums.size();
        std::sort(nums.begin(), nums.end());
        if (L <= 2) return;

        for (int i = 1; i < L-1; i+=2 )
            std::swap(nums[i], nums[i+1]);
    }
};