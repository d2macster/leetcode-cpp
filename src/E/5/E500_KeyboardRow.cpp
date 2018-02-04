//
// Created by Andrii Cherniak on 2/3/18.
//
#include <vector>
#include <string>

using std::vector;
using std::string;

class Solution {
public:
    vector<string> findWords(vector<string> &words) {
        int m[255];
        vector<string> result;

        for (char ch: "qwertyuiop") m[ch] = 0;
        for (char ch: "asdfghjkl") m[ch] = 1;
        for (char ch: "zxcvbnm") m[ch] = 2;
        bool checksum[3], wl;
        for (string w : words) {
            for (int i = 0; i <= 2; i++ )checksum[i] = false;
            wl = w.length();
            for (char ch: w) checksum[m[std::tolower(ch)]] = true;
            if (checksum[0] + checksum[1] + checksum[2] == 1) result.push_back(w);
        }
        return result;
    }
};