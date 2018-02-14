//
// Created by Andrii Cherniak on 2/2/18.
//
#include <vector>
using std::vector;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int L = nums.size();
        int left = 0, right = L-1;
        for (int i = 0; i <= right; i++){
            if (nums[i] == 0) std::swap(nums[i], nums[left++]);
            else if (nums[i] == 2) std::swap(nums[i--], nums[right--]);
        }

    }
};