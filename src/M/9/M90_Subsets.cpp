//
// Created by Andrii Cherniak on 3/14/18.
//
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<vector<int> > subsetsWithDup(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        int L = nums.size();

        vector<vector<int> > subsets;
        subsets.push_back(vector<int>());
        for (int i = 0; i < nums.size();) {
            int count = 0;
            while (i + count < L && nums[i] == nums[i + count]) count++;
            int ss = subsets.size();
            for (int j = 0; j < ss; j++) {
                vector<int> vs = subsets[j];
                for (int k = 1; k <= count; k++) {
                    vs.push_back(nums[i]);
                    subsets.push_back(vs);
                }
            }
            i += count;
        }

        return subsets;
    }
};