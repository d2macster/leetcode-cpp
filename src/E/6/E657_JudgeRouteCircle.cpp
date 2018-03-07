//
// Created by Andrii Cherniak on 3/7/18.
//
#include <string>
#include <unordered_map>
using std::string;
using std::unordered_map;

class Solution {
public:
    bool judgeCircle(string moves) {
        unordered_map<char , int> m;
        for (char ch: moves) m[ch] ++;
        if (m['U'] && m['U'] != m['D']) return false;
        if (m['L'] && m['L'] != m['R']) return false;
        return true;
    }
};