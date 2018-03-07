//
// Created by Andrii Cherniak on 3/7/18.
//
#include <string>
using std::string;

class Solution {
public:
    bool detectCapitalUse(string word) {
        int L = word.length();
        int capital_count = 0;
        for (char ch: word)
            if (isupper(ch)) capital_count ++;
        if (!capital_count) return true;
        if (capital_count == L) return true;
        if (capital_count == 1 && L >= 2 && isupper(word[0])) return true;
        return false;
    }
};