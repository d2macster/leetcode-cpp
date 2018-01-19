//
// Created by Andrii Cherniak on 1/19/18.
//
#include <vector>
using std::vector;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int > row = vector<int >(std::max(0, rowIndex + 1), 1);
        int n = rowIndex;
        double v = 1;
        for (int k = 1; k < rowIndex; k++){
            v *= (n - k + 1);
            v /= k;
            row[k] = (int) v;
        }
        return row;
    }
};