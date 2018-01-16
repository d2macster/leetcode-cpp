//
// Created by Andrii Cherniak on 1/16/18.
//

class Solution {
public:
    int numTrees(int n) {
        if (n <= 0) return 0;
        if (n == 1)
            return 1;

        int bst[n + 1];
        for (int i = 0; i <= n; i++) bst[i] = 0;
        bst[0] = 1;
        bst[1] = 1;
        for (int i = 2; i <= n; i++) {
            for (int j = 1; j <= i; j++) bst[i] += bst[j - 1] * bst[i - j];
        }

        return bst[n];
    }
};