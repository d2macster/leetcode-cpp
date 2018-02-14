//
// Created by Andrii Cherniak on 1/22/18.
//
#include <vector>
using std::vector;
using std::min;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int L = nums.size();
        if (L == 0) return 0;
        if (L == 1) return nums[0];
        int left = 0, right = L-1, mid;
        while (right - left > 3){
            mid = (left + right) / 2;
            if (nums[left] < nums[right]) right = mid;
            else if (nums[mid] < nums[right]) right = mid;
            else left = mid;
        }
        int min_v = nums[left];
        for (int i = left+1; i <= right; i++) min_v = min(min_v, nums[i]);
        return min_v;
    }
};