//
// Created by Andrii Cherniak on 1/30/18.
//

#include <iostream>
#include <vector>
using std::vector;

class Solution {
public:
    bool checkPossibility(vector<int> &nums) {
        int L = nums.size();
        if (L <= 2) return true;
        int violations = 0, left, right;
        for (int i = 1; i < L; i++){
            if (nums[i] < nums[i-1]){
                violations++;
                if (i < 2 || nums[i-2] <= nums[i]) nums[i-1] = nums[i];
                else nums[i] = nums[i-1];
            }
        }

        return violations <= 1;
    }
};