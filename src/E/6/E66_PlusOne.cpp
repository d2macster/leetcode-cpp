//
// Created by Andrii Cherniak on 1/18/18.
//
#include <vector>

using std::vector;

class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        int L = digits.size();

        int overflow = 1;
        for (int i = L-1; i >= 0; i--){
            digits[i] = digits[i] + overflow;
            if (digits[i] == 10){
                digits[i] = 0;
                overflow = 1;
            } else overflow = 0;
        }
        if (overflow != 0)
        digits.insert(digits.begin(), overflow);
        return digits;
    }
};