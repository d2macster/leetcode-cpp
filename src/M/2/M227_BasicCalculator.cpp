//
// Created by Andrii Cherniak on 3/20/18.
//
#include <string>

using namespace std;

class Solution {
    void helper(int &sum, int &tmp, int & v, char op) {
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
    }

public:
    int calculate(string s) {
        int v = 0, sum = 0, tmp = 0;
        char op = '+';

        for (char c: s) {
            if (c >= '0' && c <= '9') v = v * 10 + (c - '0');
            else if (c == '+' || c == '-' || c == '*' || c == '/') {
                helper(sum, tmp, v, op);

                op = c;
                v = 0;
            }
        }

        helper(sum, tmp, v, op);

        return sum + tmp;
    }
};