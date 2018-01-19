//
// Created by Andrii Cherniak on 1/19/18.
//
#include <vector>
using std::vector;
using std::min;
using std::max;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int L = height.size();
        int volume = 0;
        int l = 0, r = L-1;

        while (l < r){
            volume = max(volume, min(height[l], height[r]) * (r - l));
            if (height[l] > height[r]) r--;
            else l++;
        }
        return volume;
    }
};