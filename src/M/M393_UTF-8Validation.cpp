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
                if ((d & 0b11111000) == 0b11110000) chars = 3;
                else if ((d & 0b11110000) == 0b11100000) chars = 2;
                else if ((d & 0b11100000) == 0b11000000) chars = 1;
                else if ((d & 0b10000000) == 0b00000000) chars = 0;
                else return false;
            } else{
                if ((d & 0b11000000) == 0b10000000) chars --;
                else return false;
            }
        }
        return chars == 0;
    }
};