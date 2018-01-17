//
// Created by Andrii Cherniak on 1/16/18.
//
#include <iostream>

class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if (n <= 0)
            return 1;
        int choices[] = {9, 9, 8, 7, 6, 5, 4, 3, 2, 1};
        int p = 1;
        int ans = 1;
        for (int i = 0; i < std::min(n, 10); i++){
            p *= choices[i];
            ans += p;
        }
        return ans;

    }
};