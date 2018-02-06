//
// Created by Andrii Cherniak on 2/5/18.
//
#include <vector>


using std::vector;

class Solution {
public:
    vector<int> findErrorNums(vector<int> &nums) {
        int n = nums.size();
        int key;
        vector<int> answer = vector<int>(2, 0);
        for (int i = 0; i < n; i++) {
            key = abs(nums[i]) - 1;
            if (nums[key] < 0) answer[0] = key + 1;
            else nums[key] *= -1;
        }

        for (int i = 0; i < n; i++)
            if (nums[i] > 0) answer[1] = i + 1;

        return answer;

    }
};