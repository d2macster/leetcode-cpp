//
// Created by Andrii Cherniak on 1/12/18.
//
#include <vector>

using std::vector;

class Solution {
public:
    int maxSubArray(vector<int> &nums) {
        int L = nums.size();
        if (L == 0) return 0;
        int result = nums[0];
        int ss = nums[0];
        for (int i = 1; i < L; i++){
            ss += nums[i];
            ss = (nums[i] > ss)? nums[i] : ss;
            result = (ss > result) ? ss : result;
        }
        return result;
    }
};