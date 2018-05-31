//
// Created by Andrii Cherniak on 5/31/18.
//
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int shortestWordDistance(vector<string> &words, string word1, string word2) {
        int L = words.size();
        int D = L, d = 0;
        int p1 = -1, p2 = -1;

        for (int i = 0; i < L; i++){
            if (words[i] == word2){
                if (word1 == word2) p2 = p1;
                else p2 = i;
            }

            if (words[i] == word1)
                p1 = i;


            if (p1 >= 0 && p2 >= 0){
                d = abs(p1 - p2);
                D = min(D, d);
            }
        }

        return D;

    }
};