//
// Created by Andrii Cherniak on 2/9/18.
//
#include <limits>

#include <iostream>

class Solution {
public:
    int divide(int dividend, int divisor) {
        if ((divisor == 0) || (dividend == INT_MIN && divisor == -1)) return INT_MAX;
        if (divisor == 1)
            return dividend;
        int result = 0;
        int sign = (dividend < 0 ^ divisor < 0)? -1 : 1;

        long n = labs(dividend);
        long d = labs(divisor);

        while (n >= d){

            long v = d;
            int mult = 1;
            while (n >= (v << 1)){
                v <<= 1;
                mult <<= 1;
            }
            n -= v;
            result += mult;
        }

        return (sign == 1)? result: -result;
    }
};