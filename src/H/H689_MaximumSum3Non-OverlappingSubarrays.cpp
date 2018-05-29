//
// Created by Andrii Cherniak on 5/25/18.
//
#include <vector>
#include <limits>
#include <queue>

using namespace std;

class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int> &nums, int k) {
        vector<int> result = vector<int>(3, 0);
        if (k == 0)
            return result;
        int L = nums.size();
        vector<int> sums = vector<int>(L, INT_MIN);
        vector<int> left = vector<int>(L, -1);
        vector<int> right = vector<int>(L, -1);

        sums[0] = 0;
        for (int i = 0; i < k; i++) sums[0] += nums[i];
        for (int i = 1; i <= L - k; i++)
            sums[i] = sums[i - 1] - nums[i - 1] + nums[i + k - 1];

        int left_id = 0;
        for (int i = 0; i <= L - k; i++) {
            if (sums[i] > sums[left_id]) left_id = i;
            left[i] = left_id;
        }
        int right_id = L - k;
        for(int i = L - k; i >= 0; i--){
            if (sums[i] >= sums[right_id]) right_id = i;
            right[i] = right_id;
        }

        int maxS = INT_MIN;
        int tmp, l, r;
        for (int i = k; i <= L - 2*k; i++){
            l = left[i-k];
            r = right[i+k];
            tmp = sums[l] + sums[i] + sums[r];
            if (tmp > maxS){
                maxS = tmp;
                result[0] = l;
                result[1] = i;
                result[2] = r;
            }
        }


        return result;
    }
};