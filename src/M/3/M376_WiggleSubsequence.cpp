//
// Created by Andrii Cherniak on 3/30/18.
//
#include <vector>

using namespace std;

class Solution {
    int changeCounter(vector<int> &nums, int change) {
        int counter = 0;
        for (int i = 0; i < nums.size() - 1; i++) {
            if (change > 0) {
                if (nums[i + 1] > nums[i]) {
                    counter++;
                    change = -1;
                }
            } else if (change < 0) {
                if (nums[i + 1] < nums[i]) {
                    counter++;
                    change = +1;
                }
            }
        }

        return counter;
    }

public:
    int wiggleMaxLength(vector<int> &nums) {
        int L = nums.size();
        if (L < 2) return L;

        return 1 + max(changeCounter(nums, 1), changeCounter(nums, -1));
    }
};