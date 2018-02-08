//
// Created by Andrii Cherniak on 2/8/18.
//
class Solution {
public:
    int mySqrt(int x) {
        long v = long(x);
        long guess = v;

        while (guess*guess  >v)
            guess = (guess + v/guess) / 2;

        return guess;

    }
};