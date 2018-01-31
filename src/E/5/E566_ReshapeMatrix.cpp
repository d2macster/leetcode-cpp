//
// Created by Andrii Cherniak on 1/31/18.
//
#include <vector>

using std::vector;

class Solution {
public:
    vector<vector<int> > matrixReshape(vector<vector<int> > &nums, int r, int c) {
        int R = nums.size();
        if (R == 0) return nums;
        int C = nums[0].size();
        if (C == 0) return nums;
        if (R * C != r * c) return nums;

        vector<vector<int> > result = vector<vector<int> >(r, vector<int>(c, 0));
        int el_id = 0;
        for (int rr = 0; rr < R; rr++)
            for (int cc = 0; cc < C; cc++) {
                result[el_id / c][el_id % c] = nums[rr][cc];
                el_id++;
            }
        return result;
    }
};