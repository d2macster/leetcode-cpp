//
// Created by Andrii Cherniak on 4/12/18.
//
#include <string>

using namespace std;

class Solution {
public:
    bool canWin(string s) {
        int L = s.size();
        for (int i = 0; i < L - 1; i++) {
            if (s[i] == '+' && s[i + 1] == '+') {
                s[i] = s[i + 1] = '-';
                if (!canWin(s))
                    return true;
                s[i] = s[i + 1] = '+';
            }
        }
        return false;
    }
};