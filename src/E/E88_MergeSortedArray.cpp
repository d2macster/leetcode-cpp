//
// Created by Andrii Cherniak on 1/18/18.
//
#include <vector>

using std::vector;

class Solution {
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n) {
        if (n == 0)
            return;
        int i = n + m - 1;
        int p1 = m - 1, p2 = n - 1;
        while (p1 >= 0 && p2 >= 0) {
            if (nums1[p1] > nums2[p2]) {
                nums1[i] = nums1[p1];
                nums1[p1--] = 0;
            } else
                nums1[i] = nums2[p2--];
            i--;
        }
        while (p2 >= 0)
            nums1[i--] = nums2[p2--];
    }
};