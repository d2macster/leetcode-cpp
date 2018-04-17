//
// Created by Andrii Cherniak on 4/17/18.
//
#include <vector>
#include <iostream>

using namespace std;

class NumArray {
    vector<int> nums;
    int L;
    int pow2;
    vector<int> sTree;
    int sTreeL;

    void buildSTree(int pos, int left, int right) {
        if (left > right) return;
        if (left == right) {
            sTree[pos] = (left < L) ? nums[left] : 0;
        } else {
            int mid = (left + right) / 2;
            buildSTree(2 * pos + 1, left, mid);
            buildSTree(2 * pos + 2, mid + 1, right);
            sTree[pos] = sTree[2 * pos + 1] + sTree[2 * pos + 2];
        }
    }

public:
    NumArray(vector<int> n) {
        nums = n;
        L = nums.size();
        pow2 = 1;
        while (pow2 < L) pow2 <<= 1;
        sTreeL = 2 * pow2 - 1;
        sTree = vector<int>(sTreeL, 0);
        buildSTree(0, 0, pow2 - 1);

    }

    void update(int i, int val) {
        int delta = val - nums[i];
        nums[i] = val;
        int pos = sTreeL - L + i - (pow2 - L);
        while (pos >= 0) {
            sTree[pos] += delta;
            if (pos == 0) break;
            pos = (pos - 1) / 2;
        }
    }

    int sumRangeHelper(int i, int j, int pos, int left, int right) {
        if (i <= left && j >= right) return sTree[pos];
        else if (j < left || i > right) return 0;
        else {
            int mid = (left + right) / 2;
            return sumRangeHelper(i, j, 2 * pos + 1, left, mid) + sumRangeHelper(i, j, 2 * pos + 2, mid + 1, right);
        }
    }

    int sumRange(int i, int j) {
        return sumRangeHelper(i, j, 0, 0, pow2 - 1);
    }
};