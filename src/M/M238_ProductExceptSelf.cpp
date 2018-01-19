//
// Created by Andrii Cherniak on 1/19/18.
//
#include <vector>

using std::vector;

class Solution {
public:
    vector<int> productExceptSelf(vector<int> &nums) {
        int L = nums.size();
        vector<int> answer = vector<int>(L, 0);
        long pnz = 1;
        int zc = 0;
        for (int i = 0; i < L; i++) {
            if (nums[i] != 0) pnz *= nums[i];
            else zc++;
        }
        if (zc > 1)
            for (int i = 0; i < L; i++) answer[i] = 0;
        else if (zc == 1)
            for (int i = 0; i < L; i++)
                answer[i] = nums[i] == 0 ? pnz : 0;
        else for (int i = 0; i < L; i++) answer[i] = pnz / nums[i];
        return answer;
    }
};