//
// Created by Andrii Cherniak on 2/5/18.
//
#include <string>
using std::string;

class Solution {
public:
    bool canPermutePalindrome(string s) {
        int L = s.length();
        if (L <= 1) return true;
        int hash[255];
        for (int i = 0; i < 255; i++) hash[i] = 0;
        for (char ch: s) hash[ch]++;
        int counter[2] = {0, 0};
        for (int i = 0; i < 255; i++) {
            counter[hash[i] % 2]++;
        }
        return (counter[1] <= 1);
    }
};