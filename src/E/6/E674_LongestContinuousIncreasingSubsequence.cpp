//
// Created by Andrii Cherniak on 1/30/18.
//
#include <vector>
#include <limits>
using std::vector;

class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int prev = INT_MIN, counter = 0, maxl = 0;

        for (const int & n: nums){
            if (n > prev){
                counter++;
            } else{
                maxl = std::max(maxl, counter);
                counter = 1;
            }
            prev = n;
        }
        maxl = std::max(maxl, counter);
        return maxl;
    }
};