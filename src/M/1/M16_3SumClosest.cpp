//
// Created by Andrii Cherniak on 1/23/18.
//
#import <vector>

using std::vector;
using std::abs;

class Solution {
public:
    int threeSumClosest(vector<int> &nums, int target) {
        int L = nums.size();
        if (L <= 2) return 0;
        std::sort(nums.begin(), nums.end());
        int result = nums[0] + nums[1] + nums[2];
        int diff1 = abs(target - result);
        int j, k, sum, diff2;
        for (int i = 0; i < L - 2; i++) {
            j = i + 1;
            k = L - 1;

            while (j < k) {
                sum = nums[i] + nums[j] + nums[k];
                diff2 = sum - target;
                if (abs(diff2) < diff1){
                    result = sum;
                    diff1 = abs(diff2);
                }
                if (diff2 > 0) k--;
                else if (diff2 < 0) j++;
                else return result;
            }
        }
        return result;
    }
};