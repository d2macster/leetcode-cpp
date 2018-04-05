//
// Created by Andrii Cherniak on 4/5/18.
//
#include <vector>

using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int> &nums) {
        int L = nums.size();
        vector<int> forward_sum = vector<int>(L, 0);
        vector<int> backwards_sum = vector<int>(L, 0);
        int s = 0;
        for (int i = 0; i < L; i++) {
            s = (nums[i] == 0) ? 0 : s + nums[i];
            forward_sum[i] = s;
        }
        s = 0;
        for (int i = L - 1; i >= 0; i--) {
            s = (nums[i] == 0) ? 0 : s + nums[i];
            backwards_sum[i] = s;
        }

        int maxL = 0;
        for (int i = 0; i < L; i++){
            maxL = max(maxL, forward_sum[i]);
            if (nums[i] == 0) {
                int left = (i > 0) ? forward_sum[i - 1] : 0;
                int right = (i < L - 1) ? backwards_sum[i + 1] : 0;
                maxL = max(maxL, left + 1 + right);
            }
        }

        return maxL;
    }
};