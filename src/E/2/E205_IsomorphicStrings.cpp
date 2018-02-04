//
// Created by Andrii Cherniak on 2/4/18.
//
#include <string>
using std::string;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int Ls = s.length();
        int Lt = t.length();
        if (Ls != Lt) return false;
        if (Ls <= 1) return true;
        int hashS[255], hashT[255];
        for (int i = 0; i < 255; i++) {
            hashS[i] = Ls;
            hashT[i] = Ls;
        }
        for (int i = 0; i < Ls; i++) hashS[s[i]] = std::min(hashS[s[i]], i);
        for (int i = 0; i < Ls; i++) hashT[t[i]] = std::min(hashT[t[i]], i);

        for (int i = 0; i < Ls; i++){
            if (hashS[s[i]] != hashT[t[i]]) return false;
        }
        return true;
    }
};