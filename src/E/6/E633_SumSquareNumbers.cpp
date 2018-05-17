//
// Created by Andrii Cherniak on 5/17/18.
//
#include <cmath>
using namespace std;

class Solution {
public:
    bool judgeSquareSum(int c) {
        if (c < 0) return false;
        for (int i = 0; i <= sqrt(c); i++){
            int diff = c - i * i;
            int diffq = sqrt(diff);
            if (diffq * diffq == diff) return true;
        }
        return false;
    }
};