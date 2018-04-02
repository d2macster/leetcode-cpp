//
// Created by Andrii Cherniak on 4/2/18.
//

class Solution {
public:
    int trailingZeroes(int n) {
        long p = 5, nL = long(n);
        int counter = 0;

        while ( nL / p > 0){
            counter += nL / p;
            p *= 5;
        }

        return counter;
    }
};