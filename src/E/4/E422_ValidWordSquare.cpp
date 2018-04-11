//
// Created by Andrii Cherniak on 4/10/18.
//
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    bool validWordSquare(vector<string> &words) {
        int L = words.size();
        if (L == 0) return true;
        for (int i = 0; i < L; i++) if (words[i].size() > L) return false;
        for (int i = 0; i < L; i++) {
            int Lw = words[i].size();
            for (int j = Lw; j < L; j++) if (words[j].size() > i) return false;
            for (int j = 0; j < Lw; j++) if (words[i][j] != words[j][i]) return false;

        }
        return true;
    }
};