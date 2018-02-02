//
// Created by Andrii Cherniak on 2/1/18.
//
#include <string>

using std::string;

class Solution {
public:
    int strStr(string haystack, string needle) {
        int Lh = haystack.length();
        int Ln = needle.length();
        if (haystack == needle)
            return 0;
        if (Ln == 0)
            return 0;
        int match;
        if (Lh == 0 || Ln > Lh) return -1;
        for (int i = 0; i < Lh - Ln + 1; i++) {
            match = 0;
            for (int j = 0; j < Ln; j++) {
                if (haystack[i + j] != needle[j]) break;
                match++;
            }
            if (match == Ln) return i;
        }
        return -1;
    }
};