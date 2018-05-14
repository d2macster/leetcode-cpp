//
// Created by Andrii Cherniak on 5/14/18.
//
#include <cmath>
using namespace std;

class Solution {
public:
    bool checkPerfectNumber(int num) {
        if (num < 1) return false;
        int sum = 0;
        int ss = sqrt(num);
        for (int i = 1; i <= ss; i++) {
            if (num % i == 0) {
                sum += i;
                if (i > 1) sum += num / i;
            }
        }
        if (ss * ss == num) sum -= ss;

        return (sum == num);
    }
};