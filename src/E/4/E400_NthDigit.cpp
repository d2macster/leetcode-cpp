//
// Created by Andrii Cherniak on 4/10/18.
//
#include <cmath>
#include <string>
using namespace std;

class Solution {
public:
    int findNthDigit(int n) {
        long long digits = 0L;
        for (int d = 1; d <= 11; d++){
            long long upper_v = pow(10L, d) - 1L;
            long long lower_v = pow(10L, d-1);
            long long range_digits = (upper_v - lower_v + 1)*d + digits;
            if (n >= digits && n <= range_digits){
                long n_diff = n - digits - 1;
                long val = (n <= 9) ? n : (n_diff / d + lower_v);
                string s = to_string(val);
                return (s[n_diff % d] - '0');
            }
            digits = range_digits;
        }
        return 0;
    }
};