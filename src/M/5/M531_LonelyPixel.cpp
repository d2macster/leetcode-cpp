//
// Created by Andrii Cherniak on 3/29/18.
//
#include <vector>

#include <unordered_set>
using namespace std;

class Solution {
public:
    int findLonelyPixel(vector<vector<char>>& picture) {
        int R = picture.size();
        if (R == 0) return 0;
        int C = picture[0].size();
        if (C == 0) return 0;
        vector<int> counterR = vector<int >(R, 0);
        vector<int> counterC = vector<int >(C, 0);

        for (int r = 0; r < R; r++)
            for (int c = 0; c < C; c++)
                if (picture[r][c] == 'B'){
                    counterR[r]++;
                    counterC[c]++;
                }
        int result = 0;
        for (int r = 0; r < R; r++)
            for (int c = 0; c < C; c++)
                if (picture[r][c] == 'B' && counterR[r] == 1 && counterC[c] == 1)
                    result++;

        return result;
    }
};