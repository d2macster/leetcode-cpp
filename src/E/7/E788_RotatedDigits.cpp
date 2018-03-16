//
// Created by Andrii Cherniak on 3/16/18.
//

class Solution {
    bool isGood(int n) {
        int hash[10];
        for (int i = 0; i <= 9; i++) hash[i] = 0;
        while (n > 0) {
            hash[n % 10]++;
            n /= 10;
        }
        if (hash[3] || hash[4] || hash[7]) return false;
        if (!(hash[2] || hash[5] || hash[6] || hash[9])) return false;
        return true;
    }

public:
    int rotatedDigits(int N) {
        int counter = 0;
        for (int i = 1; i <= N; i++) {
            counter += isGood(i);
        }
        return counter;
    }
};