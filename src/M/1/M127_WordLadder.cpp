//
// Created by Andrii Cherniak on 2/14/18.
//
#include <vector>
#include <string>
#include <unordered_set>

using std::vector;
using std::string;
using std::unordered_set;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string> &wordList) {
        unordered_set<string> set_next;
        vector<string> v1, v2;
        int wL = beginWord.length();

        for (string w: wordList) set_next.insert(w);
        if (set_next.find(endWord) == set_next.end())
            return 0;
        v1.push_back(beginWord);
        int dist = 1;
        while (!v1.empty()) {
            dist++;
            for (string w: v1) {
                for (int p = 0; p < wL; p++) {
                    char ch = w[p];
                    for (char c = 'a'; c <= 'z'; c++) {
                        w[p] = c;
                        if (set_next.find(w) != set_next.end()) {
                            if (w == endWord)
                                return dist;
                            v2.push_back(w);
                            set_next.erase(w);
                        }
                    }
                    w[p] = ch;
                }
            }
            v1 = v2;
            v2.clear();
        }
        return 0;
    }
};