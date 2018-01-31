//
// Created by Andrii Cherniak on 1/31/18.
//
#include <vector>
#include <limits>

using std::vector;

class Solution {
public:
    int dominantIndex(vector<int> &nums) {
        int L = nums.size();
        if (L == 0)
            return -1;
        if (L == 1)
            return 0;
        int max_v = nums[0], max_v_id = 0, max_v_2;
        int max_v2 = INT_MIN, max_v2_id = -1;

        for (int i = 1; i < L; i++) {
            if (nums[i] > max_v2) {
                max_v2 = nums[i];
                max_v2_id = i;
                if (max_v2 > max_v) {
                    std::swap(max_v, max_v2);
                    std::swap(max_v_id, max_v2_id);
                }
            }
        }
        if (max_v >= 2 * max_v2) return max_v_id;
        else return -1;
    }
};