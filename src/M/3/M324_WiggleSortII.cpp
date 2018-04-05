//
// Created by Andrii Cherniak on 4/5/18.
//
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void wiggleSort(vector<int> &nums) {
        vector<int> copy = nums;
        sort(copy.begin(), copy.end());
        int L = nums.size();
        int oddN = (L % 2 == 0)?L/2:L/2+1;
        int even_id = L-1;
        int odd_id = oddN-1;
        for (int i = 0; i < L; i++)
            nums[i] = (i%2 == 0)?copy[odd_id--]:copy[even_id--];
    }
};