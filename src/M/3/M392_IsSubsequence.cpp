//
// Created by Andrii Cherniak on 1/17/18.
//
#include <string>

using std::string;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int Ls = s.length();
        int Lt = t.length();
        if (Ls > Lt) return false;
        if (Ls == 0) return true;
        int ps = 0, pt = 0;
        while ((ps < Ls) && (pt < Lt)) {
            if (s[ps] == t[pt]) ps++;
            pt++;
        }
        if (ps == Ls) return true;
        else return false;
    }
};