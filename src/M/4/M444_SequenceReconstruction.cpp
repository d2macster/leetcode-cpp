//
// Created by Andrii Cherniak on 5/10/18.
//

#include <vector>

using namespace std;


class Solution {
public:
    bool sequenceReconstruction(vector<int> &org, vector<vector<int>> &seqs) {
        int n = org.size();
        if (n == 0) return false;
        if (n == 1){
            bool matched = false;
            for (const auto &ss: seqs) {
                if (ss.size() > 1) return false;
                if (ss.size() == 1 && org[0] != ss[0]) return false;
                if (ss.size() == 1 && org[0] == ss[0]) matched = true;
            }
            if (!matched) return false;
        }
        if (n >= 2) {
            vector<int> pos = vector<int>(n + 1, 0);
            vector<bool> match = vector<bool>(n - 1, false);
            for (int i = 0; i < n; i++) pos[org[i]] = i;

            for (const auto &ss: seqs) {
                int ls = ss.size();
                if (ls == 0) continue;
                for (int i = 0; i < ls; i++) {
                    if (ss[i] <= 0 || ss[i] > n) return false;
                }
                for (int i = 0; i < ls - 1; i++) {
                    if (pos[ss[i]] > pos[ss[i + 1]]) return false;
                    if (pos[ss[i + 1]] - pos[ss[i]] == 1) {
                        match[pos[ss[i]]] = true;
                    }
                }
            }

            for (int i = 0; i < n-1; i++) if (!match[i]) return false;
        }
        return true;
    }
};