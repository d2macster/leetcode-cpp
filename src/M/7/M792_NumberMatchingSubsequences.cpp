//
// Created by Andrii Cherniak on 5/24/18.
//
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int numMatchingSubseq(string S, vector<string> &words) {
        vector<vector<string>> groups = vector<vector<string>>(26, vector<string>());
        int id, Lw;
        char c;
        for(string w: words){
            id = w[0] - 'a';
            groups[id].push_back(w);
        }
        int L = S.size();

        for (int i = 0; i < L; i++){
            id = S[i] - 'a';
            vector<string> g_w = groups[id];
            groups[id].clear();
            for (string w: g_w){
                Lw = w.size();
                if (Lw > 1){
                    string next_w = w.substr(1);
                    id = next_w[0] - 'a';
                    groups[id].push_back(next_w);
                }
            }
        }
        int cnt = 0;
        for (int i = 0; i < 26; i++) cnt += groups[i].size();
        return words.size() - cnt;
    }
};