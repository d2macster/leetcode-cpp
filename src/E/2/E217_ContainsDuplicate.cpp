//
// Created by Andrii Cherniak on 1/18/18.
//
#include <vector>

using std::vector;

class Solution {
public:
    bool containsDuplicate(vector<int> &nums) {
        int L = nums.size();
        if (L <= 1)
            return false;
        std::sort(nums.begin(), nums.end());
        for (int i = 1; i < L; i++) if (nums[i] == nums[i - 1]) return true;
        return false;
    }
};