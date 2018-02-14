//
// Created by Andrii Cherniak on 2/1/18.
//
#include <string>
using std::string;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int L = s.length();
        if (L <= 1)
            return L;
        int m[256];
        for (int i = 0; i < 256; i++) m[i] = -1;

        int result = 1;
        int l = 0, r = 1;
        m[s[0]] = 0;
        char ch;
        while (r < L){
            ch = s[r];
            if (m[ch] != -1){
                int i = l;
                l = m[ch] + 1;
                for (; i <l; i++)
                    m[s[i]] = -1;
            }
            result = std::max(result, r - l + 1);
            m[ch] = r;
            r++;
        }

        return result;
    }
};