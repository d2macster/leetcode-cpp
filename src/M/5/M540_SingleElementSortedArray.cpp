//
// Created by Andrii Cherniak on 5/21/18.
//
#include <vector>

using namespace std;

class Solution {
    int helper(vector<int> &nums, int l, int r) {
        int L = nums.size();
        if (r - l < 3) {
            int single = -1;
            for (int i = l; i <= r; i++) {
                single = nums[i];
                if (i > 0 && nums[i - 1] == nums[i]) single = -1;
                if (i < L - 1 && nums[i + 1] == nums[i]) single = -1;
                if (single != -1) return single;
            }
            return -1;
        }
        int mid = l + (r - l) / 2;
        if (nums[mid - 1] != nums[mid] && nums[mid + 1] != nums[mid]) return nums[mid];
        int pair = mid;
        if (nums[mid + 1] == nums[mid]) pair = mid + 1;
        if (pair % 2 == 1) return helper(nums, pair + 1, r);
        else return helper(nums, l, pair - 2);
    }

public:
    int singleNonDuplicate(vector<int> &nums) {
        int L = nums.size();
        return helper(nums, 0, L - 1);
    }
};