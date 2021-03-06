//
// Created by Andrii Cherniak on 4/2/18.
//

class Solution {
public:
    bool isUgly(int num) {
        if (num < 1) return false;
        if (num == 1) return true;
        if (num % 2 == 0) return isUgly(num/2);
        else if (num % 3 == 0) return isUgly(num/3);
        else if (num % 5 == 0) return isUgly(num/5);
        else return false;
    }
};