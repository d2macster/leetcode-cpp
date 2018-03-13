//
// Created by Andrii Cherniak on 3/13/18.
//
#include <vector>
#include <map>
#include <algorithm>


using namespace std;

class Solution {
public:
    void nextPermutation(vector<int> &nums) {
        int L = nums.size();
        if (L <= 1) return;
        map<int, int> m;
        map<int, int>::iterator it;

        for (int i = L - 1; i >= 0; i--) {
            it = m.upper_bound(nums[i]);
            if (it != m.end()) {
                std::swap(nums[i], nums[it->second]);
                std::sort(nums.begin() + i + 1, nums.end());
                return;
            }
            m[nums[i]] = i;
        }
        std::sort(nums.begin(), nums.end());
    }
};