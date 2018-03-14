//
// Created by Andrii Cherniak on 3/13/18.
//
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> codes;
        codes.push_back(0);
        if (n <= 0) return codes;
        for (int bits = 1; bits <= n; bits++) {
            int mask = (1 << (bits - 1));
            vector<int> prev_codes = codes;
            reverse(prev_codes.begin(), prev_codes.end());
            for (int c : prev_codes) codes.push_back(mask | c);
        }
        return codes;
    }
};