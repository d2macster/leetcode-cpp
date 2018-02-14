//
// Created by Andrii Cherniak on 1/11/18.
//
#include <vector>

using std::vector;

class Solution {
public:
    vector<int> singleNumber(vector<int> &nums) {
        unsigned int xor_v = 0;
        for (int n: nums) {
            xor_v ^= n;
        }
        int shift = 0;
        while ((xor_v & 1) == 0) {
            xor_v >>= 1;
            shift++;
        }
        unsigned int xor_v0 = 0;
        unsigned int xor_v1 = 0;

        for (int n: nums) {
            if (((n >> shift) & 1) == 0)
                xor_v0 ^= n;
            else xor_v1 ^= n;

        }

        vector<int> result(2);

        result[0] = xor_v0;
        result[1] = xor_v1;

        return result;

    }
};