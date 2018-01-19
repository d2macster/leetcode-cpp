//
// Created by Andrii Cherniak on 1/18/18.
//
#include <vector>

using std::vector;
using std::abs;

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int> &nums) {
        vector<int> answer;
        int n = nums.size();
        int n_id;
        for (int i = 0; i < n; i++){
            n_id = abs(nums[i])-1;
            if (nums[n_id] > 0) nums[n_id] *= -1;
        }

        for (int i = 0; i < n; i++){
            if (nums[i] > 0) answer.push_back(i + 1);
        }

        return answer;
    }
};