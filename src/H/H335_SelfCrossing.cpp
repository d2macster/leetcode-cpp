//
// Created by Andrii Cherniak on 5/30/18.
//
#include <vector>

using namespace std;

class Solution {
public:
    bool isSelfCrossing(vector<int> &x) {
        int L = x.size();
        if (L <= 3) return false;

        for (int i = 3; i <= min(L - 1, 3); i++) {
            if (x[i] >= x[i - 2] && x[i - 1] <= x[i - 3]) return true;
        }

        for (int i = 4; i <= min(L - 1, 4); i++) {
            if (x[i] >= x[i - 2] && x[i - 1] <= x[i - 3]) return true;
            if (x[i] + x[i - 4] >= x[i - 2] && x[i - 1] == x[i - 3]) return true;
        }

        for (int i = 5; i < L; i++) {
            if (x[i] >= x[i - 2] && x[i - 1] <= x[i - 3]) return true;
            if (x[i] + x[i - 4] >= x[i - 2] && x[i - 1] == x[i - 3]) return true;
            if (x[i - 5] - x[i - 3] + x[i - 1] >= 0 && x[i - 3] >= x[i - 1] && x[i - 2] >= x[i - 4] &&
                x[i - 4] - x[i - 2] + x[i] >= 0)
                return true;
        }

        return false;
    }
};