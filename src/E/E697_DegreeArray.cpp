//
// Created by Andrii Cherniak on 1/29/18.
//
#include <vector>
#include <unordered_map>
#include <iostream>

using std::vector;
using std::unordered_map;

class Solution {
public:
    int findShortestSubArray(vector<int> &nums) {
        int L = nums.size();
        if (L <= 1)
            return L;
        unordered_map<int, int> counter;
        unordered_map<int, int> lv;
        unordered_map<int, int> rv;
        int max_count = 1;
        for (int i = 0; i < L; i++) {
            if (counter.find(nums[i]) == counter.end()) {
                counter[nums[i]] = 1;
                lv[nums[i]] = i;
                rv[nums[i]] = i;
            }else {
                counter[nums[i]]++;
                max_count = std::max(max_count, counter[nums[i]]);
                rv[nums[i]] = i;
            }
        }
        int answer = L;
        for (std::pair<int, int> el : counter){
            if (el.second == max_count){
                answer = std::min(answer, rv[el.first] - lv[el.first] + 1);
            }
        }
        return answer;

    }
};