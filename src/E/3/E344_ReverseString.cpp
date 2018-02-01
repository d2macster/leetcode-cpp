//
// Created by Andrii Cherniak on 2/1/18.
//
#include <string>

using std::string;

class Solution {
public:
    string reverseString(string s) {
        int L = s.length();
        if (L <= 1) return s;
        int lo = 0, hi = L - 1;
        while (lo < hi)
            std::swap(s[lo++], s[hi--]);
        return s;

    }
};