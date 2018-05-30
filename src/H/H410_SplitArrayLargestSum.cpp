//
// Created by Andrii Cherniak on 5/29/18.
//
#include <vector>
#include <limits>

using namespace std;

class Solution {
    bool canSplit(vector<int> &nums, int m, long cap) {
        long s = 0;
        int counter = 1;
        int L = nums.size();
        for (int i = 0; i < L; i++) {
            if (s + nums[i] <= cap) s += nums[i];
            else {
                counter++;
                s = nums[i];
            }
            if (counter > m) return false;
        }
        return true;
    }

public:
    int splitArray(vector<int> &nums, int m) {
        long lower = 0, upper = 0, med;
        for(int n: nums) lower = max(lower, long(n));
        if (nums.size() <= m) return lower;

        for (int n: nums) upper += n;
        while (upper - lower >= 4) {
            med = lower + (upper - lower) / 2;
            if (canSplit(nums, m, med)) upper = med;
            else lower = med + 1;
        }
        for (long c = lower; c <= upper; c++) if (canSplit(nums, m, c)) return c;
        return 0;
    }
};