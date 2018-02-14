//
// Created by Andrii Cherniak on 2/2/18.
//
#include <vector>

using std::vector;

class Solution {
public:
    int threeSumSmaller(vector<int> &nums, int target) {
        int L = nums.size();
        std::sort(nums.begin(), nums.end());

        int triplets = 0;
        int i, j;
        for (int k = 2; k < L; k++){
            if (nums[0] + nums[1] + nums[k] > target) break;
            i = 0;
            j = k - 1;
            while (i < j){
                if (nums[i] + nums[j] + nums[k] < target){
                    triplets += j - i;
                    i++;
                }else j--;
            }
        }
        return triplets;
    }
};