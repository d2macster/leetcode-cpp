//
// Created by Andrii Cherniak on 3/7/18.
//
#include <string>
#include <algorithm>

using std::string;



class Solution {
public:
    string reverseWords(string s) {
        int L = s.length();
        for (int i = 0; i < L; i++){
            if (s[i] != ' ') {
                int j = i;
                for (; j < L && s[j] != ' '; j++){}
                std::reverse(s.begin() + i, s.begin() + j);
                i = j;
            }
        }

        return s;
    }
};