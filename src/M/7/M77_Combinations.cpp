//
// Created by Andrii Cherniak on 3/13/18.
//
#include <vector>

using namespace std;

class Solution {
    void helper(vector<int> &seq, vector<vector<int> > &combinations, int num, int n, int k) {
        if (k == 0) {
            vector<int> seq_copy = seq;
            combinations.push_back(seq_copy);
            return;
        }
        if (num > n) return;
        helper(seq, combinations, num + 1, n, k);
        seq[k - 1] = num;
        helper(seq, combinations, num + 1, n, k - 1);
    }

public:
    vector<vector<int> > combine(int n, int k) {
        vector<vector<int> > combinations;
        if (k > n || n <= 0 || k <= 0) return combinations;
        vector<int> nums;
        for (int num = 1; num <= n; num++) nums.push_back(num);
        vector<int> seq = vector<int>(k, 0);
        helper(seq, combinations, 1, n, k);
        return combinations;
    }
};