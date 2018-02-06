//
// Created by Andrii Cherniak on 2/6/18.
//
#include <vector>
#include <string>
#include <unordered_set>
#include <iostream>

using std::vector;
using std::string;
using std::unordered_set;

class Solution {
public:
    string longestWord(vector<string>& words) {
        sort(words.begin(), words.end());
        unordered_set<string> built;
        string res;
        for (string w : words) {
            if (w.size() == 1 || built.count(w.substr(0, w.size() - 1))) {
                res = w.size() > res.size() ? w : res;
                built.insert(w);
            }
        }
        return res;
    }
};