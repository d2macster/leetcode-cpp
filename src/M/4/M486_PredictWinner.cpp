//
// Created by Andrii Cherniak on 4/12/18.
//
#include <vector>
using namespace std;

class Solution {
    int score(vector<int>& nums, int left, int right, int turn){
        if (left == right) return turn*nums[left];
        int s1 = turn * nums[left] + score(nums, left+1, right, -turn);
        int s2 = turn * nums[right] + score(nums, left, right-1, -turn);
        return (turn > 0)?max(s1, s2):min(s1, s2);
    }
public:
    bool PredictTheWinner(vector<int>& nums) {
        int L = nums.size();
        if (L <= 2) return true;
        return (score(nums, 0, L-1, 1) >=0);
    }
};