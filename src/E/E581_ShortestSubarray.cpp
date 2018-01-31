//
// Created by Andrii Cherniak on 1/30/18.
//
#include <vector>

using std::vector;

class Solution {
public:
    int findUnsortedSubarray(vector<int> &nums) {
        int L = nums.size();
        if (L <= 1) return 0;
        int lo = 0, hi = L - 1;
        while (lo < L && nums[lo] <= nums[lo + 1]) lo++;
        while (hi > 0 && nums[hi - 1] <= nums[hi]) hi--;
        if (lo >= hi) return 0;
        int max_v = nums[lo];
        int min_v = nums[hi];
        for (int i = lo; i <= hi; i++) max_v = std::max(nums[i], max_v);
        for (int i = lo; i <= hi; i++) min_v = std::min(nums[i], min_v);
            int answer = L;
            for (int i = 0; i <= lo; i++) if (nums[i] <= min_v) answer--;
            for (int i = hi; i < L; i++) if (nums[i] >= max_v) answer--;

        return answer;

    }
};