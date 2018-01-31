//
// Created by Andrii Cherniak on 1/9/18.
//
#include <bitset>

class Solution {
public:
    int hammingWeight(uint32_t n) {
        std::bitset<32> bs(n);
        return bs.count();
    }
};