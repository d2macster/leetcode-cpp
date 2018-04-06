//
// Created by Andrii Cherniak on 4/5/18.
//
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int> &nums, int k) {
        if (k == 0)
            return 0;
        int cnt = 0;
        long kk = long(k);

        int L = nums.size();
        if (L == 0)
            return 0;


        int left = 0;
        long p = 1L;
        for (int right = 0; right < L && left < L; right++){
            p *= nums[right];
            while (p >= kk && left < L) p /= nums[left++];
            cnt += right - left + 1;
        }

        return max(0, cnt);
    }
};