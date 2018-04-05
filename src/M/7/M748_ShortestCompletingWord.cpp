//
// Created by Andrii Cherniak on 4/4/18.
//
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string shortestCompletingWord(string licensePlate, vector<string> &words) {
        vector<int > signature = vector<int >(26, 0);
        for (char c: licensePlate) {
            if (c >= 'a' && c <= 'z') signature[c-'a']++;
            if (c >= 'A' && c <= 'Z') signature[c-'A']++;
        }
        string word = "";
        for (string & w: words){
            vector<int > s_copy = signature;
            for (char c: w)
                if (s_copy[c - 'a'] > 0) s_copy[c - 'a']--;
            bool check_ok = true;
            for (int i = 0; i < 26 && check_ok; i++) if (s_copy[i] > 0) check_ok = false;
            if (check_ok) {
                if (word == "") word = w;
                else if (w.size() < word.size()) word = w;
            }
        }

        return word;
    }
};