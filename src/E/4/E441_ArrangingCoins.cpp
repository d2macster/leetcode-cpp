//
// Created by Andrii Cherniak on 3/1/18.
//
#include <iostream>
#include <cmath>

class Solution {
public:
    int arrangeCoins(int n) {
        return (sqrt(1L + 8*long(n)) - 1)/2;
    }
};