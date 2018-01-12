//
// Created by Andrii Cherniak on 1/11/18.
//
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int> > subsets(vector<int> &nums) {
        vector<vector<int> > result;
        result.push_back(vector<int>());
        int L = nums.size();
        for (int i = 0; i < L; i++){
            int R = result.size();
            for (int j = 0; j < R; j++){
                vector<int> vv = result[j];
                vv.push_back(nums[i]);
                result.push_back(vv);
            }
        }

        return result;
    }
};