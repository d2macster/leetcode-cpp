//
// Created by Andrii Cherniak on 2/6/18.
//
#include <string>
#include <map>
#include <vector>

using std::string;
using std::map;
using std::vector;

class Solution {
public:
    string frequencySort(string s) {
        int hash[255];
        for (int i = 0; i < 255; i++) hash[i] = 0;
        for (char ch: s) hash[ch]++;
        map<int, vector<char> > counter;
        for (int i = 0; i < 255; i++)
            if (hash[i] > 0) counter[hash[i]].push_back(i);


        int r_id = 0;
        for (auto p = counter.rbegin(); p != counter.rend(); p++) {
            for (char ch: p->second)
                for (int i = 1; i <= p->first; i++) s[r_id++] = ch;
        }

        return s;
    }
};