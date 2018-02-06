//
// Created by Andrii Cherniak on 2/6/18.
//
#include <vector>
#include <unordered_map>

using std::vector;
using std::unordered_map;

class Solution {
public:
    vector<int> topKFrequent(vector<int> &nums, int k) {
        unordered_map<int, int> counter(nums.size());
        for (const int n: nums) counter[n]++;
        vector<int> topK = vector<int>(k, 0);
        vector<vector<int> > buckets = vector<vector<int> >(nums.size() + 1, vector<int>());
        for (auto p: counter)
            buckets[p.second].push_back(p.first);

        int cc = 0;

        for (int i = nums.size(); i > 0; i--){
            for (int v : buckets[i]){
                topK[cc++] = v;
                if (cc >= k) return topK;
            }
        }
        return topK;
    }
};