//
// Created by Andrii Cherniak on 4/11/18.
//
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> constructArray(int n, int k) {
        vector<int> nums = vector<int>(n, 0);
        for (int i = 1; i <= n - k; i++) nums[i-1] = i;
        int lo = n - k + 1;
        int hi = n;
        int begin = n - k + 1;
        for (int i = begin; i <= n ; i++) nums[i-1] = ((i - begin) % 2 == 0)?hi--:lo++;
        return nums;
    }
};