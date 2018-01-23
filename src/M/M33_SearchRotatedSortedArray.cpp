//
// Created by Andrii Cherniak on 1/23/18.
//
#import <vector>

using std::vector;

class Solution {
public:
    int search(vector<int> &nums, int target) {
        int L = nums.size();
        if (L == 0) return -1;
        int lo = 0, hi = L - 1, mid;
        while (hi - lo > 2) {
            mid = (lo + hi) / 2;
            if (nums[mid] < nums[hi]) {
                if (target >= nums[mid] && target <= nums[hi]) lo = mid;
                else hi = mid - 1;
            } else {
                if (target >= nums[lo] && target <= nums[mid]) hi = mid;
                else lo = mid + 1;
            }
        }
        for (int i = lo; i <= hi; i++)
            if (nums[i] == target) return i;
        return -1;
    }
};