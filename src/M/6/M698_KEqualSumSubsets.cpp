//
// Created by Andrii Cherniak on 3/23/18.
//
#include <vector>
#include <iostream>

using namespace std;

class Solution {
    bool search(vector<int> &groups, vector<int> &nums, int target, int k) {
        if (nums.empty()) return true;
        int v = nums[nums.size() - 1];
        nums.pop_back();
        for (int i = 0; i < k; i++) {
            if (groups[i] + v <= target) {
                groups[i] += v;
                if (search(groups, nums, target, k))
                    return true;
                groups[i] -= v;
            }
            if (groups[i] == 0) break;
        }

        nums.push_back(v);

        return false;
    }

public:
    bool canPartitionKSubsets(vector<int> &nums, int k) {
        int sum = 0;
        int L = nums.size();
        for (int n: nums) sum += n;
        if (sum % k != 0 || L < k) return false;
        int target = sum / k;
        sort(nums.begin(), nums.end());
        if (nums[L - 1] > target) return false;
        while (nums[nums.size() - 1] == target) {
            nums.pop_back();
            k--;
        }

        vector<int> groups = vector<int>(k, 0);

        return search(groups, nums, target, k);
    }
};