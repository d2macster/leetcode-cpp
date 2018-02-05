//
// Created by Andrii Cherniak on 2/4/18.
//
#include <string>
#include <unordered_map>
#include <sstream>

using std::string;
using std::unordered_map;
using std::istringstream;

class Solution {
public:
    bool wordPattern(string pattern, string str) {
        unordered_map<string, char> w2c;
        unordered_map<char, string> c2w;
        istringstream in(str);
        int i = 0, pl = pattern.length();
        for (string w; in >> w; i++) {
            if (i >= pl)
                return false;
            if (w2c.find(w) == w2c.end())
                w2c[w] = pattern[i];
            if (c2w.find(pattern[i]) == c2w.end())
                c2w[pattern[i]] = w;
            if (w2c[w] != pattern[i] || c2w[pattern[i]] != w)
                return false;
        }
        return (i == pl);
    }
};