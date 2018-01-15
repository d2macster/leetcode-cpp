//
// Created by Andrii Cherniak on 1/15/18.
//
#include <vector>
#include <string>
#include <unordered_set>
#include <iostream>

using std::vector;
using std::string;
using std::unordered_set;

class Solution {
public:
    bool wordBreak(string s, vector<string> &wordDict) {
        unordered_set<string> ws;
        for (string w : wordDict) ws.insert(w);

        int L = s.length();
        bool dp[L];
        for (int i = 0; i < L; i++) dp[i] = false;

        for (int i = 0; i < L; i++) {
            for (int j = 1; j <= i; j++) {
                if (dp[j-1] && ws.find(s.substr(j, i - j + 1)) != ws.end()) dp[i] = true;
            }
            if (ws.find(s.substr(0, i + 1)) != ws.end()) dp[i] = true;

        }

        return dp[L - 1];
    }
};