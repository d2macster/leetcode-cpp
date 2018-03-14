//
// Created by Andrii Cherniak on 3/14/18.
//
#include <vector>
#include <iostream>

using namespace std;

class Solution {
    void helper(int k, int n, int begin, vector<int> &path, vector<vector<int> > &combinations) {
        if (k == 0 && n == 0) {
            combinations.push_back(path);
        } else if (k <= 0 || n <= 0 || begin > 9) return;

        for (int i = begin; i <= 9; i++) {
            if (n >= i) {
                path[k - 1] = i;
                helper(k - 1, n - i, i+1, path, combinations);
            }
        }
    }

public:
    vector<vector<int> > combinationSum3(int k, int n) {
        vector<vector<int> > combinations;
        if (k < 1 || n < 1)
            return combinations;
        vector<int> path = vector<int>(k, 0);
        helper(k, n, 1, path, combinations);
        return combinations;
    }
};