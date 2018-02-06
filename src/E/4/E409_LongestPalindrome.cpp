//
// Created by Andrii Cherniak on 2/5/18.
//
#include <string>
using std::string;

class Solution {
public:
    int longestPalindrome(string s) {
        int L = s.length();
        int hash[255];
        for (int i = 0; i < 255; i++) hash[i] = 0;
        for (char ch: s) hash[ch] ++;
        int odds = 0;
        for (int i = 0; i < 255; i++) odds += (hash[i] % 2);
        return L - odds + (odds > 0);
    }
};