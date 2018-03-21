//
// Created by Andrii Cherniak on 3/21/18.
//
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        int Ls = s.size();
        int Lt = t.size();
        if (Lt > Ls) return isOneEditDistance(t, s);

        if (Ls - Lt > 1) return false;
        bool mismatch = false;
        for (int i = 0; i < Lt; i++) {
            if (s[i] != t[i]) {
                if (Ls == Lt) t[i] = s[i];
                else t.insert(i, 1, s[i]);
                mismatch = true;
                break;
            }
        }
        
        return ((!mismatch && Ls == Lt + 1) || (mismatch && s == t));
    }
};