//
// Created by Andrii Cherniak on 1/29/18.
//
#include <vector>
#include <iostream>

using std::vector;

class Solution {
public:
    int searchInsert(vector<int> &nums, int target) {
        int L = nums.size();
        if (L == 0) return 0;
        int lo = 0, hi = L - 1, mid;
        while (hi - lo > 3) {
            mid = (lo + hi) / 2;
            if (target < nums[mid]) hi = mid - 1;
            else if (target > nums[mid]) lo = mid + 1;
            else
                return mid;
        }
        if (target < nums[lo]) return lo;
        else if (target > nums[hi]) return hi + 1;
        for (int i = lo; i <= hi; i++){
            if (nums[i] >= target) return i;
        }
    }
};