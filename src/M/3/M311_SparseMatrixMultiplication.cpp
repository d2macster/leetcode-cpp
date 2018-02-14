//
// Created by Andrii Cherniak on 2/6/18.
//
#include <vector>
using std::vector;

class Solution {
public:
    vector<vector<int> > multiply(vector<vector<int> >& A, vector<vector<int> >& B) {
        int RA = A.size(), RB = B.size(), CA = A[0].size(), CB = B[0].size();

        vector<vector<int> > product = vector<vector<int> >(RA, vector<int>(CB, 0));
        for (int r = 0; r < RA; r++)
            for (int c = 0; c < CA; c++){
                if (A[r][c] != 0){
                    for (int cc = 0; cc < CB; cc++)
                        product[r][cc] += A[r][c] * B[c][cc];
                }
            }
        return product;
    }
};