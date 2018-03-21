//
// Created by Andrii Cherniak on 3/21/18.
//
#include <vector>
#include <string>
#include <unordered_map>
#include <iostream>

using namespace std;

class Solution {
    string shift(string s) {
        int L = s.size();
        for (int i = 0; i < L; i++)
            s[i] = (s[i] + 1 <= 'z') ? s[i] + 1 : 'a';
        return s;
    }

public:
    vector<vector<string> > groupStrings(vector<string> &strings) {
        unordered_map<string, int> counter;
        vector<vector<string> > groups;

        for (string ss: strings) counter[ss]++;
        sort(strings.begin(), strings.end());
        for (string ss: strings) {
            if (counter[ss]) {
                string next = ss;
                vector<string> group;
                do {
                    for (int i = 1; i <= counter[next]; i++) group.push_back(next);
                    counter[next] = 0;
                    next = shift(next);
                } while (next != ss);

                groups.push_back(group);
            }
        }

        return groups;
    }
};