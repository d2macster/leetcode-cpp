//
// Created by Andrii Cherniak on 3/29/18.
//
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int findBlackPixel(vector<vector<char>> &picture, int N) {
        if (N == 0)
            return 0;

        int R = picture.size();
        if (R == 0) return 0;
        int C = picture[0].size();
        if (C == 0) return 0;
        vector<unordered_set<int> > counterR = vector<unordered_set<int> >(R, unordered_set<int>());
        vector<unordered_set<int> > counterC = vector<unordered_set<int> >(C, unordered_set<int>());


        for (int r = 0; r < R; r++)
            for (int c = 0; c < C; c++)
                if (picture[r][c] == 'B') {
                    counterR[r].insert(c);
                    counterC[c].insert(r);
                }

        int result = 0;
        for (int r = 0; r < R; r++)
            for (int c = 0; c < C; c++)
                if (picture[r][c] == 'B' && counterR[r].size() == N && counterC[c].size() == N) {
                    bool lonely = true;
                    for (int row:counterC[c])
                        if (counterR[row] != counterR[r]) {
                            lonely = false;
                            break;
                        }
                    result += lonely;
                }

        return result;
    }
};