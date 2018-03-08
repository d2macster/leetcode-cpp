//
// Created by Andrii Cherniak on 3/8/18.
//
#include <vector>
#include <algorithm>
using std::vector;
using std::swap;

class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int L = nums.size();
        for (int i = 0; i < L - 1; i++){
            if (i & 1){
                if (nums[i] < nums[i+1]) swap(nums[i], nums[i+1]);
            }else{
                if (nums[i] > nums[i+1]) swap(nums[i], nums[i+1]);
            }
        }
    }
};