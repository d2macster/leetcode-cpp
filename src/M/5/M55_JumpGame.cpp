//
// Created by Andrii Cherniak on 3/30/18.
//
#include <vector>

using namespace std;

class Solution {
public:
    bool canJump(vector<int> &nums) {
        int L = nums.size();
        vector<bool > jump = vector<bool >(L, false);
        int i = 0, advance = min(L-1, nums[0]);
        while (i <= advance){
            jump[i] = true;
            advance = min(L-1, max(advance, i + nums[i]));
            i++;
        }

        return jump[L-1];
    }
};