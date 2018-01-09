//
// Created by Andrii Cherniak on 1/9/18.
//

#include <vector>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int tmp = nums[0];
        for(int i = 1; i < nums.size(); ++i)
        {
            tmp ^= nums[i];
        }
        return tmp;
    }
};
