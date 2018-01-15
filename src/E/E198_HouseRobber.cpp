//
// Created by Andrii Cherniak on 1/15/18.
//
#include <vector>

using std::vector;

class Solution {
public:
    int rob(vector<int> &nums) {
        int L = nums.size();
        int p1 = 0;
        int p0 = 0;
        int tmp1, tmp2;
        for (int i = 0; i < L; i++) {
            tmp1 = p1;
            tmp2 = p0 + nums[i];
            p1 = tmp2 > p1 ? tmp2 : p1;
            p0 = tmp1 > p0 ? tmp1 : p0;
        }
        return p0 < p1 ? p1 : p0;
    }
};