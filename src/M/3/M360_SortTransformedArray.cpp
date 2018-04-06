//
// Created by Andrii Cherniak on 4/5/18.
//
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> sortTransformedArray(vector<int> &nums, int a, int b, int c) {
        int L = nums.size();

        for (int i = 0; i < L; i++) nums[i] = a * nums[i] * nums[i] + b * nums[i] + c;
        vector<int> result = vector<int>(L, 0);
        int left = 0, right = L - 1;
        if (a >= 0) {
            for (int i = L - 1; i >= 0; i--) {
                if (nums[left] >= nums[right])
                    result[i] = nums[left++];
                else
                    result[i] = nums[right--];
            }
        } else {
            for (int i = 0; i < L; i++) {
                if (nums[left] <= nums[right])
                    result[i] = nums[left++];
                else result[i] = nums[right--];
            }
        }
        return result;
    }
};