//
// Created by Andrii Cherniak on 1/18/18.
//
#include <unordered_set>
#include <vector>

using std::unordered_set;
using std::vector;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int> &nums, int k) {
        int L = nums.size();
        if (L <= 1) return false;
        unordered_set<int> set;
        for (int i = 0; i < L; i++){
            if (set.find(nums[i]) != set.end())
                return true;
            set.insert(nums[i]);
            if (i-k >=0) set.erase(nums[i-k]);
        }
        return false;
    }
};