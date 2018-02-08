//
// Created by Andrii Cherniak on 2/8/18.
//
#include <iostream>
class Solution {
public:
    int mySqrt(int x) {
        if (x == 0) return 0;
        if (x <= 3) return 1;
        long v = long(x);
        long l = 2L, r = x, mid, mid2;
        while (l < r - 1){
            mid = (r + l)/2;
            mid2 = mid * mid;
            if (mid2 == x) return mid;
            else if (mid2 > x) r = mid - 1;
            else l = mid;
        }
        for (long i = l; i <= r; i++){
            if (i * i <= v) mid = i;
            else return mid;
        }
        return mid;
    }
};