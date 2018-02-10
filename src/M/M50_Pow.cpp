//
// Created by Andrii Cherniak on 2/9/18.
//
#include <map>
#include <iostream>

using std::vector;
using std::map;

class Solution {
public:
    double myPow(double x, int n) {
        long p = n;
        if (p < 0) {
            p *= -1;
            x = 1.0 / x;
        }
        
        double result = 1.0;
        double vv = x * x;
        map<long, double> cache;
        long pp = 2;
        cache[pp] = vv;
        while (pp <= p) {
            cache[pp] = vv;
            pp *= 2;
            vv *= vv;
        }
        map<long, double>::reverse_iterator it;
        for (it = cache.rbegin(); it != cache.rend(); it++) {
            if (it->first <= p) {
                result *= it->second;
                p -= it->first;
            }
        }
        for (long i = 1; i <= p; i++) result *= x;
        return result;
    }
};