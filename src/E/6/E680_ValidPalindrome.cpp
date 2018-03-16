//
// Created by Andrii Cherniak on 3/16/18.
//
#include <string>

using namespace std;

class Solution {
    bool check(string &s, int l, int r, int d) {
        if (d < 0) return false;
        if (l >= r) return true;
        char ch_l = s.at(l);
        char ch_r = s.at(r);
        if (ch_l != ch_r) return check(s, l + 1, r, d - 1) || check(s, l, r - 1, d - 1);
        else
            return check(s, l + 1, r - 1, d) || check(s, l + 1, r, d - 1) || check(s, l, r - 1, d - 1);
    }

public:
    bool validPalindrome(string s) {
        return check(s, 0, s.size() - 1, 1);
    }
};