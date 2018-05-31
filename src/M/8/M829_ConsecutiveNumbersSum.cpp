//
// Created by Andrii Cherniak on 5/31/18.
//
#include <cmath>

using namespace std;

// we are solving k*x = N - (k-1)*k/2
// N - (k-1)*k/2 must be >= 0
// 2N > (k - 1)*k

class Solution {
public:
    int consecutiveNumbersSum(int N) {
        int counter = 1;

        for (int k = 2; k < sqrt(2 * N); k++) {
            int r = N - (k - 1) * k / 2;
            if (r % k == 0) counter++;
        }


        return counter;
    }
};