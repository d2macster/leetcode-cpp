//
// Created by Andrii Cherniak on 4/11/18.
//
#include <vector>

using namespace std;

class Solution {
    int helper(int pos, int N, vector<bool> &arranged) {
        if (pos == N + 1) return 1;
        if (pos > N + 1) return 0;
        int result = 0;
        for (int i = 1; i <= N; i++) {
            if (!arranged[i] && (i % pos == 0 || pos % i == 0)) {
                arranged[i] = true;
                result += helper(pos + 1, N, arranged);
                arranged[i] = false;
            }
        }
        return result;
    }

public:
    int countArrangement(int N) {
        if (N <= 0) return 0;
        vector<bool> arranged = vector<bool>(N + 1, false);
        return helper(1, N, arranged);
    }
};