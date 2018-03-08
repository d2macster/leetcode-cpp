//
// Created by Andrii Cherniak on 3/7/18.
//
#include <unordered_map>
#include <string>

using std::unordered_map;
using std::string;

class Solution {
public:
    int romanToInt(string s) {
        int L = s.size();
        if (!L)
            return 0;
        unordered_map<char, int> m;
        m['I'] = 1;
        m['V'] = 5;
        m['X'] = 10;
        m['L'] = 50;
        m['C'] = 100;
        m['D'] = 500;
        m['M'] = 1000;
        int result = 0;
        for (int i = 0; i < L; i++) {
            int v1 = m[s[i]];
            int v2 = (i + 1 < L) ? m[s[i + 1]] : 0;
            if (v1 >= v2) result += v1;
            else {
                result += v2 - v1;
                i++;
            }
        }
        return result;
    }
};