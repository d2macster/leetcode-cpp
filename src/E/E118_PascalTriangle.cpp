//
// Created by Andrii Cherniak on 1/18/18.
//
#include <vector>
using std::vector;

class Solution {
public:
    vector<vector<int > > generate(int numRows) {
        vector<vector<int > > result;
        for (int r = 1; r <= numRows; r++){
            vector<int> row = vector<int >(r, 1);
            for (int c = 1; c < r - 1; c++) row[c] = result[r-2][c-1] + result[r-2][c];
            result.push_back(row);
        }
        return result;
    }
};