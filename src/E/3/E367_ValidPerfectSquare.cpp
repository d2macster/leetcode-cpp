//
// Created by Andrii Cherniak on 2/9/18.
//

class Solution {
public:
    bool isPerfectSquare(int num) {
        if (num < 0) return false;
        if (num == 0 || num == 1) return true;
        long S = long(num);
        long x = S;
        while (x * x > S) x = (x + S/x) / 2L;
        return (x * x == S);

    }
};