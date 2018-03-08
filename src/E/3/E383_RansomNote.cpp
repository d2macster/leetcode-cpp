//
// Created by Andrii Cherniak on 3/7/18.
//
#include <string>
#include <vector>

using std::string;
using std::vector;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int > hash1 = vector<int >(26, 0);
        vector<int > hash2 = vector<int >(26, 0);
        for (char ch: ransomNote)
            hash1[ch - 'a']++;

        for (char ch: magazine)
            hash2[ch - 'a']++;

        for (int i = 0; i < 26; i++){
            if (hash1[i] > hash2[i]) return false;
        }
        return true;
    }
};