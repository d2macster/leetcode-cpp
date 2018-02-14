//
// Created by Andrii Cherniak on 1/12/18.
//

#include <vector>
#include <bitset>
#include <iostream>

using std::vector;
using std::bitset;

class Solution {
public:
    int totalHammingDistance(vector<int> &nums) {
        int counter[32];
        int result = 0;
        for (int i = 0; i < 32; i++)
            counter[i] = 0;
        int L = nums.size();
        for (int n: nums) {
            bitset<32> bs(n);
            for (int i = 0; i < 32; i++)
                counter[i] += bs[i];
        }

        for (int i = 0; i < 32; i++)
            result += counter[i] * (L - counter[i]);
        return result;
    }
};