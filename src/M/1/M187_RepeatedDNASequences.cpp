//
// Created by Andrii Cherniak on 1/11/18.
//
#include <vector>
#include <string>
#include <iostream>
#include <unordered_map>

using std::vector;
using std::string;
using std::unordered_map;

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> result;
        int L = s.length();
        if (L <= 10) return result;
        unordered_map<int, int> m;

        unsigned int h = 0;

        for (int i = 0; i < 9; i++) {
            h = h << 3 | (s[i] & 0b111);
        }

        for (int i = 9; i < s.length(); i++) {
            h = h << 3 | (s[i] & 0b111);
            h &= 0b00111111111111111111111111111111;
            m[h]++;
            if (m[h] == 2)
                result.push_back(s.substr(i - 9, 10));
        }

        return result;
    }
};