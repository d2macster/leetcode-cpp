//
// Created by Andrii Cherniak on 4/30/18.
//
#include <vector>
#include <limits>

using namespace std;

class Solution {
public:
    bool increasingTriplet(vector<int> &nums) {
        int L = nums.size();
        if (L < 3) return false;
        vector<vector<int>> triplet = vector<vector<int>>(L, vector<int>(2, 0));
        int min_left = INT_MAX;
        int max_right = INT_MIN;
        for (int i = 0; i < L; i++){
            triplet[i][0] = min_left;
            min_left = min(min_left, nums[i]);
        }
        for (int i = L-1; i >= 0; i--){
            triplet[i][1] = max_right;
            max_right = max(max_right, nums[i]);
        }
        for (int i = 1; i < L-1; i++){
            if (triplet[i][0] < nums[i] && triplet[i][1] > nums[i]) return true;
        }

        return false;
    }
};