#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
private:
    void helper(vector<int> &nums, int begin_pos, vector<vector<int> > &permutations) {
        if (begin_pos == nums.size()) {
            permutations.push_back(nums);
            return;
        }
        unordered_set<int> s;
        s.insert(nums[begin_pos]);
        helper(nums, begin_pos + 1, permutations);
        for (int i = begin_pos + 1; i < nums.size(); i++) {
            if (s.find(nums[i]) != s.end()) continue;
            s.insert(nums[i]);
            swap(nums[begin_pos], nums[i]);
            helper(nums, begin_pos + 1, permutations);
            swap(nums[begin_pos], nums[i]);
        }
    }

public:
    vector<vector<int> > permuteUnique(vector<int> &nums) {

        vector<vector<int> > permutations;
        helper(nums, 0, permutations);
        return permutations;
    }
};