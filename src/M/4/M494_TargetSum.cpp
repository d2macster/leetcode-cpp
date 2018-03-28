//
// Created by Andrii Cherniak on 3/28/18.
//
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;


class Solution {
public:
    int findTargetSumWays(vector<int> &nums, int S) {
        int L = nums.size();
        unordered_map<int, int> counter_prev;
        unordered_map<int, int> counter_forward;
        unordered_map<int, int> counter_backwards;


        counter_prev[0] = 1;
        counter_forward = counter_prev;


        for (int i = 0; i < L / 2; i++) {
            counter_forward.clear();
            for (auto it: counter_prev) {
                counter_forward[it.first + nums[i]] += it.second;
                counter_forward[it.first - nums[i]] += it.second;
            }
            counter_prev = counter_forward;
        }

        counter_prev.clear();
        counter_prev[0] = 1;
        counter_backwards = counter_prev;

        for (int i = L - 1; i >= L / 2; i--) {
            counter_backwards.clear();
            for (auto it: counter_prev) {
                counter_backwards[it.first + nums[i]] += it.second;
                counter_backwards[it.first - nums[i]] += it.second;
            }
            counter_prev = counter_backwards;
        }


        int ways = 0;
        for (auto it: counter_forward) {
            int diff = S - it.first;
            ways += it.second * counter_backwards[diff];
        }

        return ways;

    }
};