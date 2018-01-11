//
// Created by Andrii Cherniak on 1/10/18.
//
#include <vector>
using std::vector;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unsigned int counter1 = 0;
        unsigned int counter2 = 0;
        unsigned int overflow = 0;
        unsigned int mod3 = 0;
        for (int n : nums){
            overflow = counter1 & n;
            counter1 ^= n;
            counter2 ^= overflow;
            mod3 = counter1 & counter2;
            counter1 ^= mod3;
            counter2 ^= mod3;
        }
        return counter1;
    }
};