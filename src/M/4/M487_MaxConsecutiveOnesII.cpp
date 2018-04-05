//
// Created by Andrii Cherniak on 4/5/18.
//
#include <vector>

using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int> &nums) {
        int prev_sum = 0, cur_sum = 0;
        int maxL = 0;
        for (int n: nums) {
            cur_sum++;
            if (n == 0){
                prev_sum = cur_sum;
                cur_sum = 0;
            }
            maxL = max(maxL, cur_sum + prev_sum);
        }


        return maxL;
    }
};