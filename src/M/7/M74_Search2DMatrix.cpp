//
// Created by Andrii Cherniak on 4/5/18.
//
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target) {
        for(vector<int>& row: matrix){
            if (binary_search(row.begin(), row.end(), target)) return true;
        }
        return false;
    }
};