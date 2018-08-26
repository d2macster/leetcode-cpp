//
// Created by Andrii Cherniak on 8/26/18.
//
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findMinLR(vector<int>& nums, int l, int r) {
        if (r < l)
            return -1;
        if (r - l <= 2) {
            int minV = nums[l];
            for(int i = l+1; i <= r; i++) minV = min(minV, nums[i]);
            return minV;
        }
        int mid = (l + r)/2;
        if (nums[mid] > nums[r]) return findMinLR(nums, mid+1, r);
        else if (nums[l] > nums[mid]) return findMinLR(nums, l, mid);
        else return min(findMinLR(nums, l, mid), findMinLR(nums, mid+1, r));
    }
    int findMin(vector<int>& nums) {
        int L = nums.size();
        if (L == 0) return -1;
        if (L == 1) return nums[0];
        return findMinLR(nums, 0, L-1);
    }
};