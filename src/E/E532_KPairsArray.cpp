//
// Created by Andrii Cherniak on 1/30/18.
//

#include <vector>
#include <set>
#include <iostream>

using std::vector;


class Solution {
public:
    int findPairs(vector<int> &nums, int k) {
        int L = nums.size();
        if (L < 2)
            return 0;
        std::sort(nums.begin(), nums.end());
        int diff = 0, counter = 0;
        for (int i = 0; i < L - 1; i++) {
            int j = i + 1;
            for (; j < L, nums[j] - nums[i] < k; j++);
            if (nums[j] - nums[i] == k) counter++;
            while (i + 1 < L && nums[i] == nums[i+1]) i++;
        }

        return counter;
    }
};