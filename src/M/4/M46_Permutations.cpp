//
// Created by Andrii Cherniak on 3/13/18.
//
#include <vector>

using namespace std;

class Solution {
    void helper(vector<int> &nums, int n_id, vector<vector<int> > &result) {
        if (n_id >= nums.size()) {
            vector<int> nums_copy = nums;
            result.push_back(nums_copy);
            return;
        }
        helper(nums, n_id + 1, result);
        for (int i = n_id + 1; i < nums.size(); i++) {
            swap(nums[n_id], nums[i]);
            helper(nums, n_id + 1, result);
            swap(nums[i], nums[n_id]);
        }
    }

public:
    vector<vector<int> > permute(vector<int> &nums) {
        vector<vector<int> > result;
        int L = nums.size();
        if (!L) return result;
        if (L == 1) {
            result.push_back(nums);
            return result;
        }
        helper(nums, 0, result);
        return result;
    }
};