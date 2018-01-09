//
// Created by Andrii Cherniak on 1/9/18.
//
#include <bitset>
class Solution {
public:
    int hammingDistance(int x, int y) {
        int z = x ^ y;
        std::bitset<32> set1(z);
        return set1.count();
    }
};