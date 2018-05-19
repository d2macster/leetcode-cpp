//
// Created by Andrii Cherniak on 5/18/18.
//
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    string mostCommonWord(string paragraph, vector<string> &banned) {
        string w = "";
        string commonWord = "";
        int commonCount = 0;
        unordered_map<string, int> counter;

        for (char c: paragraph) {
            if (c == ' ' || c == '!' || c == '?' || c == ',' || c == ';' || c == '.' || c == '\'') {
                if (w != "") counter[w]++;
                w = "";
            } else w += ('a' <= c && c <= 'z') ? c : ('a' + c - 'A');
        }
        if (w != "") counter[w]++;
        for (string &b: banned) counter.erase(b);
        for (auto it: counter) {
            if (it.second > commonCount) {
                commonCount = it.second;
                commonWord = it.first;
            }
        }

        return commonWord;
    }
};