//
// Created by Andrii Cherniak on 1/9/18.
//

#include <vector>
using std::vector;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int L = nums.size();
        int v = 0;
        for (int i = 0; i <= L; i++){
            v ^= i;
        }
        for (int n: nums){
            v ^= n;
        }
        return v;
    }
};