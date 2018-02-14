//
// Created by Andrii Cherniak on 1/12/18.
//
#include <vector>
using std::vector;

class Solution {
public:
    bool validUtf8(vector<int>& data) {
        int L = data.size();
        int chars = 0;
        for(int d: data){
            if (chars == 0) {
                if ((d >> 3) == 0b11110) chars = 3;
                else if ((d >> 4) == 0b1110) chars = 2;
                else if ((d >> 5) == 0b110) chars = 1;
                else if ((d >> 7) == 1) return false;
            } else{
                if ((d >> 6) != 0b10) return false;
                chars --;
            }
        }
        return chars == 0;
    }
};