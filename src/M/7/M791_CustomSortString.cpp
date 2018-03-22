//
// Created by Andrii Cherniak on 3/22/18.
//
#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    string customSortString(string S, string T) {
        //
        vector<char> order;
        vector<int> counter = vector<int>(26, 0);

        for (int i = 0; i < S.size(); i++)
            if (i == 0 || S[i] != S[i - 1]) order.push_back(S[i]);

        for (char c: T) counter[c - 'a']++;

        int t_id = 0;
        for (char c: order) {
            for (int i = 1; i <= counter[c - 'a']; i++) T[t_id++] = c;
            counter[c - 'a'] = 0;
        }
        for(int i = 0; i < 26; i++){
            for (int j = 1; j <= counter[i]; j++) T[t_id++] = 'a'+i;
            counter[i] = 0;
        }

        return T;
    }
};