//
// Created by Andrii Cherniak on 4/2/18.
//
#include <string>

using namespace std;

class Solution {
public:
    int titleToNumber(string s) {
        int L = s.size();
        if (L == 0) return 0;
        int result = 0;
        int shift = 1;
        for (int i = L - 1; i >= 0; i--) {
            int v = (s[i] - 'A') + 1;
            if (v < 1 || v > 26)
                return 0;
            result += shift * v;
            shift *= 26;
        }
        return result;
    }
};