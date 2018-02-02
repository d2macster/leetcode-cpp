//
// Created by Andrii Cherniak on 2/1/18.
//
#include <vector>

using std::vector;

class Solution {
public:
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2) {
        int L1 = nums1.size();
        int L2 = nums2.size();
        vector<int> intersect;

        if (L1 == 0 || L2 == 0) return intersect;

        std::sort(nums1.begin(), nums1.end());
        std::sort(nums2.begin(), nums2.end());
        int i = 0, j = 0;
        while (i < L1 && j < L2) {
            if (nums1[i] > nums2[j]) j++;
            else if (nums1[i] < nums2[j]) i++;
            else {
                intersect.push_back(nums1[i]);
                i++;
                j++;
                while (nums1[i - 1] == nums1[i]) i++;
                while (nums2[j - 1] == nums2[j]) j++;
            }
        }
        return intersect;
    }
};