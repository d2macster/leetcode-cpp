//
// Created by Andrii Cherniak on 2/1/18.
//
#include <string>

using std::string;

class Solution {
    bool isaVowel(char ch){
        ch = std::tolower(ch);
        return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
    }
public:
    string reverseVowels(string s) {
        int L = s.length();
        if (L <= 1) return s;
        int lo = 0, hi = L - 1;

        while (lo < hi) {

            if (!isaVowel(s[lo])) lo++;
            else if (!isaVowel(s[hi])) hi--;
            else std::swap(s[lo++], s[hi--]);
        }
        return s;
    }
};