//
// Created by Andrii Cherniak on 2/5/18.
//
#include <string>
using std::string;

class Solution {
public:
    int numJewelsInStones(string J, string S) {
        bool hash[255];
        for (int i = 0; i < 255; i++) hash[i] = false;
        for (char ch: J) hash[ch] = true;
        int result = 0;
        for (char ch : S) result += hash[ch];
        return result;
    }
};