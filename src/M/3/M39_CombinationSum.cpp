//
// Created by Andrii Cherniak on 3/13/18.
//
#include <vector>
#include <unordered_set>
#include <iostream>

using namespace std;

class Solution {
    void helper(vector<int> &candidates, vector<int> seq, vector<vector<int> > &result, int l_id, int r_id,
                int target) {

        if (target < 0) return;
        else if (target == 0) {
            result.push_back(seq);
            return;
        }
        for (int i = l_id; i <= r_id; i++) {
            vector<int> seq_next = seq;
            seq_next.push_back(candidates[i]);
            helper(candidates, seq_next, result, i, r_id, target - candidates[i]);
        }
    }

public:
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        int L = candidates.size();
        vector<vector<int> > result;
        vector<int> seq;
        helper(candidates, seq, result, 0, L - 1, target);
        return result;
    }
};