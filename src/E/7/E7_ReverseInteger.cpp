//
// Created by Andrii Cherniak on 3/12/18.
//
#include <limits>

class Solution {
public:
    int reverse(int x) {
        if (!x)
            return 0;
        int sign = (x < 0)? -1: 1;
        x *= sign;
        long r = 0;
        while (x > 0){
            r = r * 10 + x % 10;
            x /= 10;
        }
        if (r > INT_MAX) return 0;
        return sign * r;
    }
};