//
// Created by Andrii Cherniak on 4/18/18.
//
#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
    unordered_map<char, string> pMatch;
    unordered_set<string> sMatch;

    bool search(string &pattern, string &str, int p_id, int s_id, int Lp, int Ls) {
        if (p_id == Lp)
            return (s_id == Ls);

        char pp = pattern[p_id];

        if (pMatch[pp] != "") {
            string ps = pMatch[pp];
            int Lps = ps.size();
            if (str.substr(s_id, Lps) != ps) return false;
            return search(pattern, str, p_id + 1, s_id + Lps, Lp, Ls);
        } else {
            for (int i = s_id; i < Ls; i++) {
                string candidate = str.substr(s_id, i - s_id + 1);
                if (sMatch.find(candidate) == sMatch.end()) {
                    pMatch[pp] = candidate;
                    sMatch.insert(candidate);
                    if (search(pattern, str, p_id + 1, i + 1, Lp, Ls))
                        return true;

                    pMatch[pp] = "";
                    sMatch.erase(candidate);
                }
            }
            return false;
        }
    }

public:
    bool wordPatternMatch(string pattern, string str) {
        int Lp = pattern.size();
        int Ls = str.size();
        if (Lp == 0) return (Ls == 0);
        if (Lp == 1) return (Ls > 0);

        for (char c = 'a'; c <= 'z'; c++) pMatch[c] = "";


        return search(pattern, str, 0, 0, Lp, Ls);
    }
};