//
// Created by Andrii Cherniak on 2/1/18.
//
#include <vector>

using std::vector;

class Solution {
public:
    vector<int> intersect(vector<int> &nums1, vector<int> &nums2) {
        vector<int> result;
        if (nums1.empty() || nums2.empty())
            return result;
        int L1 = nums1.size();
        int L2 = nums2.size();

        std::sort(nums1.begin(), nums1.end());
        std::sort(nums2.begin(), nums2.end());

        int i = 0, j = 0;

        while (i < L1 && j < L2){
            if (nums1[i] > nums2[j]) j++;
            else if (nums1[i] < nums2[j]) i++;
            else {
                result.push_back(nums1[i]);
                i++;
                j++;
            }
        }

        return result;
    }
};