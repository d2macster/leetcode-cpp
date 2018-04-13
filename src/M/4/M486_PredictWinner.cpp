//
// Created by Andrii Cherniak on 4/12/18.
//
#include <vector>
using namespace std;

class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        int L = nums.size();
        if (L <= 2) return true;
        vector<vector<int>> dp = vector<vector<int >>(L, vector<int>(L, 0));

        for (int left = 0; left < L; left++) dp[left][left] = nums[left];

        for (int d = 1; d < L; d++){
            for (int left = 0; left < (L - d); left++){
                int right = left+d;
                dp[left][right] = max(nums[left]-dp[left+1][right], nums[right]-dp[left][right-1]);
            }
        }

        return dp[0][L-1] >= 0;
    }
};