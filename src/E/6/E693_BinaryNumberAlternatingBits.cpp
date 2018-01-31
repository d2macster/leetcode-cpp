//
// Created by Andrii Cherniak on 1/10/18.
//

class Solution {
public:
    bool hasAlternatingBits(int n) {
        int vx = n ^ (n >> 2);


        return (vx & (vx - 1)) == 0;
    }
};