//
// Created by Andrii Cherniak on 4/5/18.
//
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int> &nums, int target) {
        vector<int> result = vector<int>(2, -1);
        int L = nums.size();
        if (L == 0) return result;
        if (target < nums[0] || target > nums[L - 1]) return result;
        int l = 0, r = L - 1;
        int begin = 2 * L, end = -2 * L;
        while (r > l + 1) {
            int med = l + (r - l) / 2;
            if (nums[med] == target) {
                begin = med;
                r = med - 1;
            } else if (target < nums[med])r = med - 1;
            else l = med + 1;
        }
        if (nums[r] == target) begin = min(begin, r);
        if (nums[l] == target) begin = min(begin, l);
        if (begin == 2 * L) return result;

        l = begin, r = L - 1;
        while (r > l + 1) {
            int med = l + (r - l) / 2;
            if (nums[med] == target) {
                end = med;
                l = med + 1;
            } else if (target < nums[med]) r = med - 1;
            else l = med + 1;
        }
        if (nums[r] == target) end = max(end, r);
        if (nums[l] == target) end = max(end, l);

        result[0] = begin;
        result[1] = end;

        return result;
    }
};