//
// Created by Andrii Cherniak on 5/23/18.
//
#include <string>
#include <vector>
#include <map>
#include <set>

using namespace std;

class Solution {
public:
    bool pyramidTransition(string bottom, vector<string> &allowed) {
        int L = bottom.size();
        if (L < 2)
            return false;
        map<string, set<char>> triple;
        for (string s: allowed) {
            string p = "";
            p += s[0];
            p += s[1];
            triple[p].insert(s[2]);
        }

        vector<set<char >>
                row = vector<set<char >>
                (L, set<char>());
        for (int i = 0; i < L; i++) row[i].insert(bottom[i]);
        while (row.size() > 1) {
            L = row.size();
            vector<set<char >>
                    next_row = vector<set<char >>
                    (L - 1, set<char>());
            for (int i = 0; i < L - 1; i++) {
                for (char c1: row[i]) {
                    for (char c2: row[i + 1]) {
                        string p = "";
                        p += c1;
                        p += c2;
                        if (triple.find(p) != triple.end()) {
                            for (char c3: triple[p]) next_row[i].insert(c3);
                        }
                    }
                }
                if (next_row[i].empty()) return false;
            }
            row = next_row;
        }
        return true;
    }
};