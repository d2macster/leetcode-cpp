//
// Created by Andrii Cherniak on 1/15/18.
//

#include <vector>

using std::vector;

class NumArray {
    int *cache;
    int L;
public:
    NumArray(vector<int> nums) {
        this->L = nums.size();
        if (this->L > 0) {
            this->cache = new int[this->L];
            this->cache[0] = nums[0];
            for (int i = 1; i < this->L; i++) {
                this->cache[i] = this->cache[i-1] + nums[i];
            }
        }

    }

    int sumRange(int i, int j) {
        int lv = (i - 1 >= 0) ? this->cache[i-1] : 0;
        return this->cache[j] - lv;
    }
};