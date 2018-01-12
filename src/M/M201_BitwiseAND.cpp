//
// Created by Andrii Cherniak on 1/11/18.
//

#include <iostream>

class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int result = n;
        unsigned int mask = 0;
        for (int i = 0; i < 32; i++){
            mask = ~(1 << i);
            if ((n & mask) >= m){
                result &= mask;
            }
        }
        result &= m;
        return result;
    }
};