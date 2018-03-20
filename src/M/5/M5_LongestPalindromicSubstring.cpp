//
// Created by Andrii Cherniak on 3/20/18.
//
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int L = s.size();
        if (L <= 1) return s;
        int bestD = 0, best_l = L, d;
        for (double pos = 0; pos < L; pos += 0.5) {
            int l = pos, r = pos + 0.5;
            while (l >= 0 && r <= L - 1 && s[l] == s[r]) {
                d = r - l + 1;
                if (d > bestD) {
                    bestD = d;
                    best_l = l;
                }
                l--;
                r++;
            }
        }
        return (bestD) ? s.substr(best_l, bestD) : "";
    }
};