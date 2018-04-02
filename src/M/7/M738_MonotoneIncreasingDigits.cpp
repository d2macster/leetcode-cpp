//
// Created by Andrii Cherniak on 4/2/18.
//
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    int monotoneIncreasingDigits(int N) {
        int result = 0;
        string S = to_string(N);
        int Ls = S.size();
        while (true) {
            int i = 0;
            for (; (i < Ls - 1) && S[i] <= S[i + 1]; i++) {};
            if (i == Ls - 1) return stoi(S);

            S[i] = '0' + (S[i] - '1');
            i++;
            for (; i < Ls; i++) S[i] = '9';

        }

    }
};