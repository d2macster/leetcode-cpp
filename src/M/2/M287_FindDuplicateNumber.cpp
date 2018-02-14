//
// Created by Andrii Cherniak on 1/22/18.
//

#include <vector>
#include <iostream>
using std::vector;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int L = nums.size();
        if (L == 1) return 0;
        int lo = 1;
        int hi = L-1;
        int counter, mid;
        while (lo < hi){
            mid = (hi + lo) / 2;
            counter = 0;
            for (int i = 0; i < L; i++) counter += nums[i] <= mid ? 1 : 0;
            if (counter > mid) hi = mid;
            else lo = mid + 1;
        }
        return lo;
    }
};