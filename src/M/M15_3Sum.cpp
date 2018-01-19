//
// Created by Andrii Cherniak on 1/19/18.
//
#include <vector>

using std::vector;

class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &nums) {
        int L = nums.size();
        vector<vector<int> > answer;
        if (L <= 2) return answer;
        std::sort(nums.begin(), nums.end());
        int j, k;
        int v;
        for (int i = 0; i < L - 2; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            if (nums[i] > 0) break;
            if (nums[i] + nums[i+1] + nums[i+2] > 0) break;
            j = i + 1;
            k = L - 1;
            while (j < k) {
                v = nums[i] + nums[j] + nums[k];
                if (v < 0) j++;
                else if (v > 0) k--;
                else {
                    if (k < L-1 && nums[k] == nums[k+1]) k--;
                    else {
                        vector<int> ids = vector<int>(3, 0);
                        ids[0] = nums[i];
                        ids[1] = nums[j++];
                        ids[2] = nums[k--];
                        answer.push_back(ids);
                    }
                }
            }

        }
        return answer;
    }
};