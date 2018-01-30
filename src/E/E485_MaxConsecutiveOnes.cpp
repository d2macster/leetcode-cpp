//
// Created by Andrii Cherniak on 1/30/18.
//
#include <vector>
using std::vector;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int L = nums.size();
        if (L == 0) return 0;
        int d = 0, begin = L;
        for (int i = 0; i < L; i++){
            if (nums[i] == 0) {
                d = std::max(d, i - begin);
                begin = L;
            }else begin = std::min(begin, i);
        }
        d = std::max(d, L - begin);
        return d;
    }
};