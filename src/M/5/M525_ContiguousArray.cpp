//
// Created by Andrii Cherniak on 4/4/18.
//
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int findMaxLength(vector<int> &nums) {
        int L = nums.size();
        vector<int> sums = vector<int>(L, 0);
        int s = 0;
        unordered_map<int, int> sum_pos;
        for (int i = 0; i < L; i++) {
            if (nums[i] == 1) s++;
            else s--;
            sums[i] = s;
            sum_pos[s] = i;
        }
        int maxL = 0;
        for (int i = L - 1; i >= 0; i--) {
            if (sums[i] == 0) maxL = max(maxL, i + 1);
            if (sum_pos.find(sums[i]) != sum_pos.end()){
                maxL = max(maxL, sum_pos[sums[i]] - i);
            }
        }

        return maxL;

    }
};