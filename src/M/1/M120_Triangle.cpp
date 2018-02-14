//
// Created by Andrii Cherniak on 1/15/18.
//
#include <vector>

using std::vector;

class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        int L = triangle.size();
        if (L == 0) return 0;
        for (int l = L-2; l >= 0; l--){
            for (int c = 0; c <= l; c++){
                triangle[l][c] += std::min(triangle[l+1][c], triangle[l+1][c+1]);
            }
        }

        return triangle[0][0];
    }
};