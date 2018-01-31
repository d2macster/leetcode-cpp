//
// Created by Andrii Cherniak on 1/31/18.
//
#include <vector>
using std::vector;

class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int L = bits.size();
        if (L == 0) return false;
        int pos = 0;
        bool onebit = false;
        while (pos < L){
            if (bits[pos] == 1){
                onebit = false;
                pos += 2;
            }else{
                onebit = true;
                pos++;
            }
        }
        return onebit;
    }
};