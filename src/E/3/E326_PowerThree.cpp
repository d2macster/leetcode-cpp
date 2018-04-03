//
// Created by Andrii Cherniak on 4/2/18.
//

class Solution {
public:
    bool isPowerOfThree(int n) {
        int maxPower = 1162261467; // 3^19
        if (n < 1 || n> maxPower) return false;
        return maxPower % n == 0;
    }
};