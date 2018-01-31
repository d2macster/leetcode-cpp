//
// Created by Andrii Cherniak on 1/30/18.
//
#include <vector>
using std::vector;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int d = 0, counter = 0;
        for (const int& n: nums){
            if (n == 1) counter++;
            else{
                d = std::max(d, counter);
                counter = 0;
            }
        }
        d = std::max(d, counter);
        return d;
    }
};