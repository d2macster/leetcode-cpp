//
// Created by Andrii Cherniak on 2/3/18.
//
#include <string>
using std::string;

class Solution {
public:
    bool isAnagram(string s, string t) {
        int hash[255];
        for (int i = 0; i < 255; i++) hash[i] = 0;
        for (char ch: s) hash[ch]++;
        for (char ch: t) hash[ch]--;
        for (int i = 0; i < 255; i++) if (hash[i] != 0) return false;
        return true;
    }
};