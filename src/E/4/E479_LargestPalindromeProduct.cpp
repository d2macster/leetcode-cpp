//
// Created by Andrii Cherniak on 5/14/18.
//
#include <string>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
    long getPalindrome(long v) {
        string s = to_string(v);
        string r = s;
        reverse(s.begin(), s.end());
        return stol(r + s);
    }

    bool check(long v, long u) {
        for (long s = sqrt(v) - 1; s < u; s++) {
            if (v % s == 0 && v / s < u) return true;
        }
        return false;
    }

public:
    int largestPalindrome(int n) {

        if (n < 1) return 0;
        if (n == 1)
            return 9;

        long upper = pow(10, n);
        for (long i = upper; i >= 1; i--) {
            long p = getPalindrome(i);
            if (check(p, upper)) return p % 1337;
        }


        return -1;
    }
};