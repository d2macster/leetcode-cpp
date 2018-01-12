//
// Created by Andrii Cherniak on 1/11/18.
//

class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int result = n & m;
        unsigned int mask = ~1;
        for (int i = 0; i < 32; i++){
            if ((n & mask) >= m){
                result &= mask;
            }
            mask = (mask << 1) | 1;

        }
        return result;
    }
};