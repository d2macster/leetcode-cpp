//
// Created by Andrii Cherniak on 2/2/18.
//
#include <vector>
using std::vector;

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int L = nums.size();
        if (L == 0) return 0;
        int answer = L + 1;
        int lo = 0, hi = 0, sum = 0;
        while (hi < L){
            sum +=nums[hi++];
            while (sum >= s){
                answer = std::min(answer, hi-lo);
                sum -= nums[lo++];
            }
        }
        return (answer == (L + 1)) ? 0 : answer;
    }
};