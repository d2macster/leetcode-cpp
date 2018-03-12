//
// Created by Andrii Cherniak on 3/12/18.
//

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0 || (x%10 == 0 && x != 0))
            return false;
        long xl = long(x);
        long xlr = 0;
        while (x > 0) {
            xlr = xlr * 10 + x % 10;
            x /= 10;
        }
        return xl == xlr;
    }
};