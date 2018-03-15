//
// Created by Andrii Cherniak on 3/15/18.
//
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        if (s.length() <= 1)
            return false;
        string s2 = s + s;
        string s2s = s2.substr(1, s2.length() - 2);
        return (s2s.find(s) != string::npos);
    }
};