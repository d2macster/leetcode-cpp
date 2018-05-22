//
// Created by Andrii Cherniak on 5/22/18.
//
#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    int countDigitOne(int n) {
        long result = 0L;
        long divider = 1L;
        long nn = long(n);

        for (long d = 1; d <= nn; d *= 10){
            divider = d * 10L;
            result += d * (n / divider) + min(d, max(nn % divider - d + 1L, 0L));
        }
        return result;
    }
};