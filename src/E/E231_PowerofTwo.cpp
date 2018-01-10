//
// Created by Andrii Cherniak on 1/9/18.
//

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n <= 0) return false;
        return (n & (n-1)) == 0;
    }
};