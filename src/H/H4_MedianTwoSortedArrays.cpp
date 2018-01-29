//
// Created by Andrii Cherniak on 1/29/18.
//
#include <vector>
#include <climits>
#include <iostream>

using std::vector;
using std::min;
using std::max;

class Solution {
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
        int N1 = nums1.size();
        int N2 = nums2.size();
        if (N1 < N2) return findMedianSortedArrays(nums2, nums1);


        int lo = 0, hi = N2 * 2, mid1, mid2;
        double L1, L2, R1, R2;
        while (lo <= hi) {
            mid2 = (lo + hi) / 2;
            mid1 = N1 + N2 - mid2;

            L1 = (mid1 == 0) ? INT_MIN : nums1[(mid1-1)/2];
            L2 = (mid2 == 0) ? INT_MIN : nums2[(mid2-1)/2];
            R1 = (mid1 == N1 * 2) ? INT_MAX : nums1[(mid1)/2];
            R2 = (mid2 == N2 * 2) ? INT_MAX : nums2[(mid2)/2];

            if (L1 > R2) lo = mid2 + 1;
            else if (L2 > R1) hi = mid2 - 1;
            else return (max(L1,L2) + min(R1, R2)) / 2;
        }
        return -1;
    }
};