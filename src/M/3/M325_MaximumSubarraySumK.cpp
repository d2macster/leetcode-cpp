//
// Created by Andrii Cherniak on 4/4/18.
//
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int maxSubArrayLen(vector<int> &nums, int k) {
        int L = nums.size();
        if (L == 0)
            return 0;
        vector<int> sums = vector<int>(L, 0);
        int s = 0;
        unordered_map<int, int> sum_pos;
        for (int i = 0; i < L; i++){
            s += nums[i];
            sums[i] = s;
            sum_pos[s] = i;
        }
        int maxL = 0;
        for (int i = 0; i < L; i++){
            if (nums[i] == k) maxL = max(maxL, 1);
            int complementary = sums[i] - nums[i] + k;
            int c_id = sum_pos[complementary];
            if (c_id > i) maxL = max(maxL, c_id - i + 1);
        }
        return maxL;
    }
};