//
// Created by Andrii Cherniak on 5/24/18.
//
#include <string>
#include <vector>
#include <set>
#include <map>

using namespace std;

class Solution {
public:
    int numMatchingSubseq(string S, vector<string> &words) {
        int L = S.size();
        map<char, set<int>> char_pos;
        for (int i = 0; i < L; i++) {
            char_pos[S[i]].insert(i);
        }
        int cnt = 0;
        set<int>::iterator it;
        for (string w: words) {
            int i = 0;
            int pos = -1;
            for (; i < w.size(); i++) {
                char c = w[i];
                if (char_pos.find(c) == char_pos.end()) break;
                it = char_pos[c].upper_bound(pos);
                if (it == char_pos[c].end()) break;
                pos = *it;
            }
            if (i == w.size()) cnt++;
        }
        return cnt;
    }
};