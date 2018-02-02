//
// Created by Andrii Cherniak on 2/1/18.
//
#include <string>
using std::string;

class Solution {
public:
    bool isPalindrome(string s) {
        int L = s.length();
        if (L <= 1) return true;
        int lo = 0, hi = L-1;
        while (lo < hi){
            if (!std::isalnum(std::tolower(s[lo]))) lo++;
            else if (!std::isalnum(std::tolower(s[hi]))) hi--;
            else
                if (std::tolower(s[lo++]) != std::tolower(s[hi--])) return false;
        }
        return true;
    }
};