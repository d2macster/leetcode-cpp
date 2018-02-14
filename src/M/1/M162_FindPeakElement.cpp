//
// Created by Andrii Cherniak on 2/8/18.
//
#include <vector>
#include <limits>

using std::vector;

class Solution {
public:
    int findPeakElement(vector<int> &nums) {
        int L = nums.size();
        if (L <= 1) return 0;
        int left = 0, right = L - 1, mid;
        while (left < right - 1){
            mid = (left + right)/2;
            if (nums[mid]  > nums[mid - 1] && nums[mid] > nums[mid + 1]) return mid;
            else if (nums[mid]  > nums[mid - 1]) left = mid + 1;
            else right = mid - 1;
        }
        return (nums[left] < nums[right])? right : left;
    }
};