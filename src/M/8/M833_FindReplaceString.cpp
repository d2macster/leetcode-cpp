//
// Created by Andrii Cherniak on 5/24/18.
//
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    string findReplaceString(string S, vector<int> &indexes, vector<string> &sources, vector<string> &targets) {
        int Li = indexes.size();
        if (Li == 0)
            return S;
        unordered_map<int, string> search_p;
        unordered_map<int, string> replace_p;
        for (int i = 0; i < Li; i++) {
            search_p[indexes[i]] = sources[i];
            replace_p[indexes[i]] = targets[i];
        }

        int Ls = S.size();
        string result = "";
        for (int i = 0; i < Ls; i++) {
            if (search_p.find(i) != search_p.end()) {
                string p = search_p[i];
                int Lp = p.size();
                bool matched = true;
                if (i + Lp > Ls) matched = false;
                for (int j = 0; matched && j < Lp && i + j < Ls; j++) {
                    if (S[i + j] != p[j]) matched = false;
                }
                if (matched) {
                    result += replace_p[i];
                    i += Lp - 1;
                } else result += S[i];
            } else result += S[i];
        }
        return result;
    }
};