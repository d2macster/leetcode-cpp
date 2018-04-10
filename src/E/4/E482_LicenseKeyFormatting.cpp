//
// Created by Andrii Cherniak on 4/10/18.
//
#include <string>
#include <vector>
#include <sstream>
#include <iostream>

using namespace std;

class Solution {
public:
    string licenseKeyFormatting(string S, int K) {
        int L = S.size();
        vector<char> symbols;
        vector<string> words;
        for (int i = 0; i < L; i++) {
            if ('a' <= S[i] && S[i] <= 'z') S[i] = 'A' + (S[i] - 'a');
            if (('A' <= S[i] && S[i] <= 'Z') || ('0' <= S[i] && S[i] <= '9')) symbols.push_back(S[i]);
        }
        int Ls = symbols.size();
        if (Ls == 0)
            return "";
        int r = Ls % K;
        ostringstream oss;

        int i = 0;
        string word = "";
        if (r > 0) {
            for (; i < r; i++) word += symbols[i];
            words.push_back(word);
        }
        for (int j = 1; j <= Ls / K; j++) {
            word = "";
            for (int k = 1; k <= K; k++) word += symbols[i++];
            words.push_back(word);
        }
        oss << words[0];
        for(int j = 1; j < words.size(); j++) oss << "-" + words[j];
        return oss.str();
    }
};