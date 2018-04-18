//
// Created by Andrii Cherniak on 4/17/18.
//
#include <vector>
#include <map>
#include <iostream>

using namespace std;

class Solution {
    void mergeSort(vector<vector<int>> &merge, vector<vector<int>> &tmp, int left, int right) {
        if (left >= right)
            return;
        int mid = (left + right) / 2;
        mergeSort(merge, tmp, left, mid);
        mergeSort(merge, tmp, mid + 1, right);
        for (int i = left; i <= right; i++) {
            tmp[i][0] = merge[i][0];
            tmp[i][1] = merge[i][1];
            tmp[i][2] = merge[i][2];
        }
        int pos = left;
        int l_pos = left, r_pos = mid + 1;
        int right_shift = 0;
        while (l_pos <= mid || r_pos <= right) {
            if (l_pos <= mid && r_pos <= right) {
                if (tmp[r_pos][0] < tmp[l_pos][0]) {
                    right_shift++;
                    merge[pos][0] = tmp[r_pos][0];
                    merge[pos][1] = tmp[r_pos][1];
                    merge[pos][2] = tmp[r_pos][2];
                    r_pos++;
                } else {
                    merge[pos][0] = tmp[l_pos][0];
                    merge[pos][1] = tmp[l_pos][1] + right_shift;
                    merge[pos][2] = tmp[l_pos][2];
                    l_pos++;
                }
            } else if (r_pos <= right) {
                right_shift++;
                merge[pos][0] = tmp[r_pos][0];
                merge[pos][1] = tmp[r_pos][1];
                merge[pos][2] = tmp[r_pos][2];
                r_pos++;
            } else {
                merge[pos][0] = tmp[l_pos][0];
                merge[pos][1] = tmp[l_pos][1] + right_shift;
                merge[pos][2] = tmp[l_pos][2];
                l_pos++;
            }
            pos++;
        }
    }

public:
    vector<int> countSmaller(vector<int> &nums) {
        int L = nums.size();
        vector<int> result = vector<int>(L, 0);

        vector<vector<int>> merge = vector<vector<int>>(L, vector<int>(3, 0));
        vector<vector<int>> tmp = vector<vector<int>>(L, vector<int>(3, 0));

        for (int i = 0; i < L; i++) {
            merge[i][0] = nums[i];
            merge[i][2] = i;
        }

        mergeSort(merge, tmp, 0, L - 1);
        for (int i = 0; i < L; i++) result[merge[i][2]] = merge[i][1];
        return result;
    }
};