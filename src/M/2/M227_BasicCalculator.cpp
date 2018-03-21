//
// Created by Andrii Cherniak on 3/20/18.
//
#include <string>

using namespace std;

class Solution {
public:
    int calculate(string s) {
        int v = 0, sum = 0, tmp = 0;
        char op = '+';

        for (char c: s) {
            if (c >= '0' && c <= '9') v = v * 10 + (c - '0');
            else if (c == '+' || c == '-' || c == '*' || c == '/') {
                if (op == '-') {
                    sum += tmp;
                    tmp = -v;
                }
                if (op == '+') {
                    sum += tmp;
                    tmp = v;
                }
                if (op == '*') tmp *= v;
                if (op == '/') tmp /= v;

                op = c;
                v = 0;
            }
        }

        if (op == '-') {
            sum += tmp;
            tmp = -v;
        }
        if (op == '+') {
            sum += tmp;
            tmp = v;
        }
        if (op == '*') tmp *= v;
        if (op == '/') tmp /= v;

        return sum + tmp;
    }
};