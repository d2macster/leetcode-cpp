//
// Created by Andrii Cherniak on 4/17/18.
//
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int> &nums) {
        int N = nums.size();
        if (N == 0) return 1;
        for (int i = 0; i < N; i++) {
            while (nums[i] >= 1 && nums[i] <= N && nums[i] != (i + 1) && nums[i] != nums[nums[i] - 1]) {
                swap(nums[i], nums[nums[i] - 1]);
            }
        }

        for (int i = 0; i < N; i++) if (nums[i] != i + 1) return (i + 1);

        return (N + 1);

    }
};