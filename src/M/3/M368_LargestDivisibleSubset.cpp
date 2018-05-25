//
// Created by Andrii Cherniak on 5/24/18.
//
#include <vector>
#include <unordered_set>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int> &nums) {
        int L = nums.size();
        if (L == 0)
            return nums;
        sort(nums.begin(), nums.end());
        unordered_map<int, unordered_set<int>> dp;
        unordered_set<int> s;
        int n1, n2;
        for (int i = 0; i < L; i++){
            n1 = nums[i];
            for(int j = 0; j < i; j++) {
                n2 = nums[j];
                if (n1 % n2 == 0 && dp[n2].size() > dp[n1].size()) dp[n1] = dp[n2];
            }
            dp[n1].insert(n1);
            if (dp[n1].size() > s.size()) s = dp[n1];
        }

        vector<int> result;
        for (int v: s) result.push_back(v);

        return result;

    }
};