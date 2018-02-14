//
// Created by Andrii Cherniak on 2/2/18.
//
#include <string>
#include <vector>
using std::vector;
using std::string;

class Solution {
public:
    string findLongestWord(string s, vector<string>& d) {
        int Ls = s.length();
        int Lw, ps, pw;
        string result = "";

        for (string w : d){
            Lw = w.length();
            ps = 0;
            pw = 0;
            while (ps < Ls && pw < Lw)
                if (s[ps++] == w[pw]) pw++;
            if (pw == Lw){
                if (pw > result.length()) result = w;
                else if (pw == result.length()) result = (result < w)? result: w;

            }
        }
        return result;
    }
};