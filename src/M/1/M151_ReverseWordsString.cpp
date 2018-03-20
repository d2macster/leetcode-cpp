//
// Created by Andrii Cherniak on 3/20/18.
//
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    void reverseWords(string &s) {
        int L = s.size();
        int i = 0, j = 0, wordCount = 0;
        while (i < L) {
            while (i < L && s[i] == ' ')i++;
            if (j > 0 && i < L) s[j++] = ' ';
            while (i < L && s[i] != ' ')
                s[j++] = s[i++];
        }
        s.resize(j);
        L = s.size();

        i = j = 0;

        while (i < L) {
            while (i < L && s[i] == ' ')i++;
            int start = i;
            while (i < L && s[i] != ' ')i++;
            reverse(s.begin() + start, s.begin() + i);
        }
        reverse(s.begin(), s.end());
    }
};