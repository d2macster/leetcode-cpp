//
// Created by Andrii Cherniak on 1/16/18.
//
#include <string>
#include <iostream>

using std::string;

class Solution {
public:
    int countSubstrings(string s) {
        int L = s.length();
        int result = L;
        int left, right;
        for (double c = 0.5; c < L; c += 0.5) {
            left = int(c - 0.5);
            right = int(c + 1);
            while (left >= 0 && right < L && s[left--] == s[right++])
                ++result;
        }
        return result;
    }
};