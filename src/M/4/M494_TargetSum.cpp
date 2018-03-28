//
// Created by Andrii Cherniak on 3/28/18.
//
#include <vector>
#include <unordered_map>
using namespace std;


class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int L = nums.size();
        unordered_map<int , int> counter_prev;
        unordered_map<int , int> counter_next;

        counter_prev[0] = 1;

        for (int n: nums){
            counter_next.clear();
            for (auto it: counter_prev){
                counter_next[it.first + n] += it.second;
                counter_next[it.first - n] += it.second;
            }
            counter_prev = counter_next;
        }


        return counter_prev[S];

    }
};