//
// Created by Andrii Cherniak on 3/16/18.
//
#include <string>
#include <vector>
#include <sstream>
#include <iostream>

using namespace std;


class Solution {
public:
    string boldWords(vector<string> &words, string S) {
        int Lw = words.size();
        int L = S.size();
        vector<bool> bitmap = vector<bool>(L, false);
        if (!Lw) return S;
        ostringstream oss;
        for (string &w: words) {
            size_t pos = S.find(w, 0);
            while (pos != string::npos) {
                for (int i = pos; i < pos + w.size(); i++) bitmap[i] = true;
                pos = S.find(w, pos + 1);
            }
        }
        for (int i = 0; i < L; i++){
            cout << bitmap[i];
            if (bitmap[i] && (i == 0 || !bitmap[i-1])) oss << "<b>";
            if (!bitmap[i] && i > 0 && bitmap[i-1]) oss << "</b>";
            oss << S.at(i);
            if (bitmap[i] && (i == L-1)) oss << "</b>";
        }
        return oss.str();
    }
};