//
// Created by Andrii Cherniak on 1/12/18.
//

class Solution {
public:
    int integerReplacement(int n) {
        unsigned int num = n;
        int cnt = 0;
        while (num > 1) {
            if ((num & 1) == 0) num >>= 1;
            else {
                if (num == 3 || __builtin_popcount(num-1) < __builtin_popcount(num + 1))
                num --;
                else num ++;
            }
            cnt++;
        }

        return cnt;
    }
};