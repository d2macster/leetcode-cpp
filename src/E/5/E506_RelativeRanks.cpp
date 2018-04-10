//
// Created by Andrii Cherniak on 4/10/18.
//
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<string> findRelativeRanks(vector<int> &nums) {
        int L = nums.size();
        if (L == 0)
            return vector<string>();
        vector<string> ranks = vector<string>(L, "");
        vector<int> copy = nums;
        unordered_map<int, int> order;
        sort(copy.begin(), copy.end());
        int order_id = 1;

        for (int i = L - 1; i >= 0; i--)
            order[copy[i]] = order_id++;

        for (int i = 0; i < L; i++){
            order_id = order[nums[i]];
            if (order_id == 1) ranks[i] = "Gold Medal";
            else if (order_id == 2) ranks[i] = "Silver Medal";
            else if (order_id == 3) ranks[i] = "Bronze Medal";
            else ranks[i] = to_string(order_id);
        }


        return ranks;
    }
};