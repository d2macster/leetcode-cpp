//
// Created by Andrii Cherniak on 1/12/18.
//
#include <string>
#include <vector>
#include <iostream>

using std::vector;
using std::string;

class Solution {
public:
    vector<string> generateAbbreviations(string word) {
        vector<string> result;
        int L = word.length();
        if (L == 0){
            result.push_back("");
            return result;
        }

        result.push_back(word);

        for (int i = 0; i < L; i++){
            for (int j = i + 1; j <= L; j++){
                string s = word.substr(0, i) + std::to_string(j - i) + word.substr(j, 1);
                if (j + 1 < L) {
                    for (string abbr: generateAbbreviations(word.substr(j + 1, L)))
                        result.push_back(s + abbr);
                }else result.push_back(s);
            }
        }
        return result;
    }
};