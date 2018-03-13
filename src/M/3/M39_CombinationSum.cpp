//
// Created by Andrii Cherniak on 3/13/18.
//
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <iostream>

using namespace std;

class Solution {
    void helper(vector<int> &candidates, vector<int> seq, vector<vector<int> > &result, int c_id,
                int target) {

        if (target < 0 || c_id >= candidates.size() || candidates[c_id] > target) return;

        helper(candidates, seq, result, c_id + 1, target);
        while (target - candidates[c_id] >= 0) {
            target -= candidates[c_id];
            seq.push_back(candidates[c_id]);
            if (target == 0) {
                result.push_back(seq);
                return;
            }
            helper(candidates, seq, result, c_id + 1, target);
        }
    }

public:
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        int L = candidates.size();
        vector<vector<int> > result;
        std::sort(candidates.begin(), candidates.end());
        vector<int> seq;
        helper(candidates, seq, result, 0, target);

        return result;
    }
};