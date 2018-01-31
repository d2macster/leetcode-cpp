//
// Created by Andrii Cherniak on 1/18/18.
//
#include <vector>
using std::vector;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int L = nums.size();
        if (L <= 1) return;
        int p0 = 0;
        for (int i = 0; i < L; i++){
            if (nums[i] != 0) nums[p0++] = nums[i];
        }
        for (; p0 < L; p0++) nums[p0] = 0;
    }
};