//
// Created by Andrii Cherniak on 5/18/18.
//
#include <vector>

using namespace std;

class Solution {
public:
    int minMoves2(vector<int> &nums) {

        int L = nums.size();
        if (L <= 1)
            return 0;

        sort(nums.begin(), nums.end());
        int median = (L % 2 == 1) ? nums[L / 2] : ((nums[L / 2] + nums[L / 2 - 1]) / 2);
        int moves = 0;
        for (int i = 0; i < L; i++) moves += abs(nums[i] - median);
        return moves;
    }
};