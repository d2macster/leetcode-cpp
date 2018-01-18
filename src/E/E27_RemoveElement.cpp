//
// Created by Andrii Cherniak on 1/18/18.
//
#include <vector>
using std::vector;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int L = nums.size();
        if (L == 0) return 0;
        int ptr = L-1;
        int i = L-1;
        while (i >= 0){
            if (nums[i] == val) {
                if (nums[ptr] != val){
                    nums[i] = nums[ptr];
                }
                ptr--;
                L--;
            }
            i--;
        }

        return L;
    }
};