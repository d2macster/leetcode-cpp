//
// Created by Andrii Cherniak on 5/14/18.
//

#include <vector>
using namespace std;

class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return 0;

        sort(nums.begin(), nums.end());
        int result = 0;
        for (int i = 1; i < n; i++) result += nums[i] - nums[0];


        return result;

    }
};