//
// Created by Andrii Cherniak on 3/28/18.
//
#include <string>
#include <iostream>

using namespace std;

class Solution {
    string parseHelper(string &s, int begin) {

        int L = s.size();
        if (begin >= L) return "";

        if (s[begin] == 'T' && (begin + 1) < L && s[begin+1] == '?') return parseHelper(s, begin+2);
        else if (s[begin] == 'F' && (begin + 1) < L && s[begin+1] == '?'){
            int level = -1;
            int i = begin+2;
            while (i < L && level != 0){
                if (s[i] == ':') level++;
                if (s[i] == '?') level--;
                i++;
            }
            return parseHelper(s, i);
        } else{
            int i = begin+1;
            while (i < L && s[i] != ':') i++;
            return s.substr(begin, i-begin);
        }

    }

public:
    string parseTernary(string expression) {
        return parseHelper(expression, 0);
    }
};