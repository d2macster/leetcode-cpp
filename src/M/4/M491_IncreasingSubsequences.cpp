//
// Created by Andrii Cherniak on 3/28/18.
//
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    vector<vector<int> > findSubsequences(vector<int> &nums) {
        set<vector<int> > candidates;
        int L = nums.size();
        for (int i = L - 1; i >= 0; i--) {
            set<vector<int> > extra_candidates;
            for (vector<int> c: candidates) {
                if (c[0] >= nums[i]) {
                    vector<int> copy = c;
                    copy.insert(copy.begin(), nums[i]);
                    extra_candidates.insert(copy);
                }
            }

            vector<int> el = vector<int>(1, nums[i]);
            candidates.insert(el);

            for (vector<int> c: extra_candidates) candidates.insert(c);

        }
        vector<vector<int> > result;
        for (vector<int> c: candidates) {
            if (c.size() > 1) result.push_back(c);
        }
        return result;

    }
};