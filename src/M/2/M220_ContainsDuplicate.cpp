//
// Created by Andrii Cherniak on 3/6/18.
//
#include <vector>
#include <algorithm>
#include <set>
using std::vector;
using std::min;
using std::set;

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        int L = nums.size();
        long tl = long(t);
        if (L <= 1 || k < 0 || t < 0) return false;
        set<long > s;


        for(int i = 0; i < L; i++){
            if (i > k) s.erase(nums[i-k-1]);
            auto it = s.lower_bound(long(nums[i]) - tl);
            if (it != s.end() && abs(nums[i] - *it) <= tl)
                return true;
            s.insert(nums[i]);
        }
        return false;
    }
};