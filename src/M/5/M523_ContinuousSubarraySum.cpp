//
// Created by Andrii Cherniak on 4/30/18.
//
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool checkSubarraySum(vector<int> &nums, int k) {
        unordered_set<int> s1, s2;
        int L = nums.size();
        if (L < 2)
            return false;

        k = abs(k);
        s1.insert(nums[0]);

        for (int i = 1; i < L; i++) {
            s2.clear();
            for (int s: s1){
                int next_v = s + nums[i];
                if (k == 0 && next_v == 0) return true;
                if (k != 0 && next_v % k == 0) return true;
                s2.insert(next_v);
            }
            s2.insert(nums[i]);
            s1 = s2;
        }

        return false;

    }
};