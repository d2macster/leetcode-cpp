//
// Created by Andrii Cherniak on 1/30/18.
//
#include <vector>
#include <string>
using std::vector;
using std::string;

class Solution {
public:
    int shortestDistance(vector<string>& words, string word1, string word2) {
        int L = words.size();
        int d = L, p1 = -L, p2 = L;
        for (int i = 0; i < L; i++){
            if (words[i] == word1) {
                p1 = i;
                d = std::min(d, abs(p1 - p2));
            }else if (words[i] == word2){
                p2 = i;
                d = std::min(d, abs(p1 - p2));
            }
        }
        return d;
    }
};