//
// Created by Andrii Cherniak on 1/12/18.
//

class Solution {
public:
    int climbStairs(int n) {
        if (n == 0)
            return 0;
        if (n == 1)
            return 1;

        int dp0 = 1;
        int dp1 = 1;
        int tmp = 0;
        for (int i = 2; i <= n; i++){
            tmp = dp0 + dp1;
            dp0 = dp1;
            dp1 = tmp;
        }
        return dp1;
    }
};