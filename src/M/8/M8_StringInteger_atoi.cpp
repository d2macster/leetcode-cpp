//
// Created by Andrii Cherniak on 3/20/18.
//
#include <string>
#include <limits>

using namespace std;

class Solution {
public:
    int myAtoi(string str) {
        int L = str.size();
        if (L == 0) return 0;
        int i = 0;
        while (i < L && str[i] == ' ')i++;
        long sign = 1;
        if (str[i] == '-') {
            sign = -1L;
            i++;
        } else if (str[i] == '+') {
            sign = 1L;
            i++;
        }
        long val = 0L;
        if ('0' > str[i] || str[i] > '9') return 0;
        while (i < L && str[i] != ' ') {
            if ('0' <= str[i] && str[i] <= '9') val = val * 10 + (str[i] - '0');
            else
                return int(sign * val);
            if (sign * val < INT_MIN) return INT_MIN;
            else if (sign * val > INT_MAX)  return INT_MAX;
            i++;
        }
        return int(sign * val);
    }
};