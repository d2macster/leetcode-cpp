//
// Created by Andrii Cherniak on 2/2/18.
//
#include <vector>
using std::vector;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int counter[3] = {0, 0, 0};
        for (const int n: nums) counter[n]++;
        int id = 0;
        for (int v = 0; v <= 2; v++)
        for (int i = 0; i < counter[v]; i++)nums[id++] = v;
    }
};