//
// Created by Andrii Cherniak on 1/11/18.
//

#include <vector>
#include <bitset>
#include <iostream>
#include <unordered_set>

using std::vector;
using std::bitset;
using std::unordered_set;


class Solution {
public:
    int findMaximumXOR(vector<int> &nums) {
        int result = 0;
        int candidate = 0;
        unsigned int mask = 0;
        for (int i = 31; i >= 0; i--){
            mask |= 1 << i;
            unordered_set<int> prefix_set;

            for (int n : nums) prefix_set.insert(n & mask);
            candidate = result | (1 << i);
            for (int v : prefix_set){
                if (prefix_set.find(v ^ candidate) != prefix_set.end()){
                    result = candidate;
                    break;
                }
            }
        }
        return result;
    }
};