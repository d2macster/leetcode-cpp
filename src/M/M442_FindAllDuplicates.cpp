//
// Created by Andrii Cherniak on 1/23/18.
//
#import <vector>
using std::vector;
using std::abs;

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> result;
        int L = nums.size();
        int v;
        for (int i = 0; i < L; i++){
            v = abs(nums[i]) - 1;
            if (nums[v] < 0) result.push_back(v + 1);
            nums[v] *= -1;
        }
        return result;
    }
};