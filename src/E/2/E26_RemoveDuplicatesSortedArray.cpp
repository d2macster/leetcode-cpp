//
// Created by Andrii Cherniak on 1/18/18.
//
#include <vector>

using std::vector;

class Solution {
public:
    int removeDuplicates(vector<int> &nums) {
        int L = nums.size();
        int Ldd = L;
        if (L <= 1) return L;
        int ptr = 0;
        for (int i = 1; i < L; i++) {
            if (nums[ptr] == nums[i])
                Ldd--;
            else if (++ptr < i)
                nums[ptr] = nums[i];
        }
        return Ldd;
    }
};