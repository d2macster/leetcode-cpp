//
// Created by Andrii Cherniak on 2/6/18.
//
#include <string>

using std::string;

class Solution {
public:
    bool isStrobogrammatic(string num) {
        int flipped[] = {0, 1, 0, 0, 0, 0, 9, 0, 8, 6};
        int lo = 0, hi = num.size() - 1, v1, v2;
        while (lo <= hi){
            v1 = num[lo++] - '0';
            v2 = num[hi--] - '0';
            if (flipped[v1] != v2 || flipped[v2] != v1) return false;
        }
        return true;
    }
};