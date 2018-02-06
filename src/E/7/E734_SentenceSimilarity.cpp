//
// Created by Andrii Cherniak on 2/6/18.
//
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>


using std::vector;
using std::string;
using std::pair;
using std::unordered_map;
using std::unordered_set;


class Solution {
public:
    bool areSentencesSimilar(vector<string> &words1, vector<string> &words2, vector<pair<string, string>> pairs) {
        int L1 = words1.size();
        int L2 = words2.size();
        if (L1 != L2) return false;
        unordered_map<string, unordered_set<string>> m;
        for (auto p: pairs) {
            m[p.first].insert(p.second);
            m[p.second].insert(p.first);
        }

        for (int i = 0; i < L1; i++)
            if (words1[i] != words2[i] && !m[words1[i]].count(words2[i])) return false;

        return true;
    }
};