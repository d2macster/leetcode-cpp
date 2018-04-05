//
// Created by Andrii Cherniak on 4/5/18.
//
#include <vector>

using namespace std;

class Solution {
public:
    void wiggleSort(vector<int> &nums) {
        int L = nums.size();
        if (L <= 1)
            return;
        vector<int> copy = nums;
        sort(copy.begin(), copy.end());
        int oddN = (L % 2 == 0) ? L / 2 : L / 2 + 1;
        vector<int>::iterator it = copy.begin();
        advance(it, oddN);
        reverse(copy.begin(), it);

        int l = 0, r = L-1;
        for (int i = 0; i < L; i++)
            nums[i] = (i % 2 == 0)?copy[l++]:copy[r--];

    }
};