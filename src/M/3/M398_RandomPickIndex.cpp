//
// Created by Andrii Cherniak on 4/29/18.
//
#include <vector>
#include <cstdlib>

using namespace std;

class Solution {
    vector<int> nums;
public:
    Solution(vector<int> nn) {
        nums = nn;
    }

    int pick(int target) {
        int index = -1;
        int cnt = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == target) {
                cnt++;
                if (cnt == 1) index = i;
                else {
                    double p = 1.0 * rand() / RAND_MAX;
                    if (p < 1.0 / cnt) index = i;
                }
            }
        }
        return index;
    }
};