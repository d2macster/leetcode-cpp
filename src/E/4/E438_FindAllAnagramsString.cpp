//
// Created by Andrii Cherniak on 2/5/18.
//
#include <vector>
#include <string>
using std::vector;
using std::string;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int Ls = s.length();
        int Lp = p.length();
        vector<int> result;
        if (Lp > Ls)
            return result;
        vector<int> hashS(26, 0), hashP(26, 0);
        for (int i = 0; i < Lp; i++){
            hashP[p[i] - 'a'] ++;
            hashS[s[i] - 'a'] ++;
        }
        if (hashS == hashP) result.push_back(0);
        for (int i = Lp; i < Ls; i++){
            hashS[s[i] - 'a']++;
            hashS[s[i-Lp] - 'a']--;
            if (hashS == hashP) result.push_back(i - Lp + 1);
        }
        return result;

    }
};