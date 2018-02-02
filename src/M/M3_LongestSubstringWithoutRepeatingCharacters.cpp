//
// Created by Andrii Cherniak on 2/1/18.
//
#include <string>
#include <unordered_map>
#include <iostream>

using std::string;
using std::unordered_map;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int L = s.length();
        if (L <= 1)
            return L;

        unordered_map<char , int> m;

        int result = 1;
        int l = 0, r = 1;
        m[s[0]] = 0;
        char ch;
        while (r < L){
            ch = s[r];
            if (m.find(ch) != m.end()){
                int i = l;
                l = m[ch] + 1;
                for (; i <l; i++)
                    m.erase(s[i]);
            }
            result = std::max(result, r - l + 1);
            m[ch] = r;
            r++;
        }

        return result;
    }
};