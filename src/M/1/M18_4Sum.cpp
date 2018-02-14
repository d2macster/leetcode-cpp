//
// Created by Andrii Cherniak on 1/31/18.
//
#include <vector>

using std::vector;

class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &nums, int target) {
        vector<vector<int> > result;
        int L = nums.size();
        if (L < 4) return result;

        std::sort(nums.begin(), nums.end());
        if (4*nums[0] > target || 4* nums[L-1] < target) return result;
        int lo, hi, s, s2;

        for (int i = 0; i < L-3; i++){
            if (i > 0 && nums[i] == nums[i-1]) continue;
            for (int j = i+1; j < L-2; j++){
                if (j > (i + 1) && nums[j] == nums[j-1]) continue;
                s = nums[i] + nums[j];
                lo = j + 1;
                hi = L - 1;
                while (lo < hi){
                    s2 = s + nums[lo] + nums[hi];
                    if (s2 > target) hi--;
                    else if (s2 < target)lo++;
                    else{
                        vector<int> tt = vector<int>(4, 0);
                        tt[0] = nums[i];
                        tt[1] = nums[j];
                        tt[2] = nums[lo];
                        tt[3] = nums[hi];
                        result.push_back(tt);
                        lo++;
                        while (lo < hi && nums[lo] == nums[lo-1]) lo++;
                        hi--;
                    }
                }
            }
        }

        return result;
    }
};