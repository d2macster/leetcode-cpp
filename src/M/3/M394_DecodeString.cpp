//
// Created by Andrii Cherniak on 3/27/18.
//
#include <string>
#include <sstream>
#include <iostream>
using namespace std;

class Solution {
public:
    string decodeString(string s) {
        if (s == "")
            return "";
        int L = s.size();
        int k = 0, i = 0;
        while (i < L && s[i] >= '0' && s[i] <= '9') {
            k = k * 10 + s[i] - '0';
            i++;
        }
        if (k == 0) {
            while (i < L && ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z')) )i++;
            string s1 = s.substr(0, i);
            string rest = s.substr(i);
            return s1 + decodeString(rest);
        }else{
            int begin = ++i;
            int cnt = 1;
            while (i < L && cnt > 0){
                if (s[i] == '[') cnt ++;
                else if (s[i] == ']') cnt--;
                i++;
            }
            string s1 = s.substr(begin, i-begin - 1);
            string rest = s.substr(i);
            string sd = decodeString(s1);
            string result = "";
            for (int i = 1; i <= k; i++) result+= sd;
            result += decodeString(rest);
            return result;
        }
    }
};