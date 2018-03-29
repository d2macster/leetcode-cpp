//
// Created by Andrii Cherniak on 3/28/18.
//
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
    void dfs(vector<int> &nums, vector<vector<int> > &result, vector<int> &sequence, int n_id) {
        int Ls = sequence.size();
        if (Ls >= 2) result.push_back(sequence);
        unordered_set<int > seen_number;
        for (int i = n_id; i < nums.size(); i++) {
            if ((Ls == 0 || nums[i] >= sequence[Ls-1] ) && (seen_number.find(nums[i]) == seen_number.end())) {
                sequence.push_back(nums[i]);
                dfs(nums, result, sequence, i+1);
                sequence.pop_back();
                seen_number.insert(nums[i]);
            }
        }
    }

public:
    vector<vector<int> > findSubsequences(vector<int> &nums) {
        vector<vector<int> > result;
        vector<int> sequence;
        dfs(nums, result, sequence, 0);
        return result;
    }
};