//
// Created by Andrii Cherniak on 3/7/18.
//
#include <vector>
#include <string>
using std::vector;
using std::string;

class Solution {
public:
    vector<string> generatePossibleNextMoves(string s) {
        vector<string> moves;
        int L = s.length();
        for(int i = 1; i < L; i++){
            if (s[i-1] == '+' && s[i] == '+'){
                string sc = s;
                sc[i-1] = '-';
                sc[i] = '-';
                moves.push_back(sc);
            }
        }
        return moves;
    }
};