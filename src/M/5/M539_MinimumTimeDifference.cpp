//
// Created by Andrii Cherniak on 3/21/18.
//
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int findMinDifference(vector<string> &timePoints) {
        int L = timePoints.size();
        vector<int> nums = vector<int>(L, 0);
        for (int i = 0; i < L; i++) {
            string &p = timePoints[i];
            int h = 10*(p[0] - '0') + (p[1] - '0');
            int m = 10*(p[3] - '0') + (p[4] - '0');
            nums[i] = h * 60 + m;
        }
        sort(nums.begin(), nums.end());
        int diff = 24 * 60;
        for (int i = 1; i < L; i++) diff = min(diff, nums[i] - nums[i - 1]);
        diff = min(diff, 24 * 60 - nums[L - 1] + nums[0]);
        return diff;
    }
};