//
// Created by Andrii Cherniak on 3/16/18.
//
#include <string>

using namespace std;

class Solution {
public:
    bool checkRecord(string s) {
        if (s == "")
            return true;
        int Acnt = 0;
        for (int i = 0; i < s.size(); i++){
            if (s.at(i) == 'A')
                Acnt++;
            if (Acnt > 1) return false;
            if (s.at(i) == 'L' && i >= 2 && s.at(i-1) == 'L' && s.at(i-2) == 'L')
                return false;
        }
        return true;
    }
};