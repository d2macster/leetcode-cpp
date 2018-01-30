#include <vector>
#include <cmath>

using std::vector;
using std::min;
using std::max;

class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>> &M) {
        int R = M.size();
        int C = M[0].size();
        vector<vector<int>> result = vector<vector<int> >(R, vector<int>(C, 0));
        int counter;
        double sum;
        for (int r = 0; r < R; r++)
            for (int c = 0; c < C; c++) {
                sum = counter = 0;
                for (int rr = max(0, r - 1); rr <= min(r + 1, R-1); rr++) {
                    for (int cc = max(0, c - 1); cc <= min(c + 1, C-1); cc++) {
                        sum += M[rr][cc];
                        counter++;
                    }
                }
                result[r][c] = std::floor(sum / counter);
            }
        return result;
    }
};