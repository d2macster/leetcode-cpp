//
// Created by Andrii Cherniak on 1/9/18.
//

class Solution {
public:
    bool isPowerOfFour(int num) {
        unsigned int mask = 0b10101010101010101010101010101010;
        return num > 0 && (num & (num - 1)) == 0 && (num & mask) == 0;
    }
};