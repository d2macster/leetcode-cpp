//
// Created by Andrii Cherniak on 2/9/18.
//
#include <vector>
using std::vector;

class Solution {
public:
    int findRadius(vector<int> &houses, vector<int> &heaters) {
        int L2 = heaters.size();
        std::sort(houses.begin(), houses.end());
        std::sort(heaters.begin(), heaters.end());
        int j = 0, r = 0;
        for (int i = 0; i < houses.size(); i++){

            while ((j + 1) < L2 && abs(houses[i] - heaters[j + 1]) <= abs(houses[i] - heaters[j]) )j++;
            r = std::max(r, abs(houses[i] - heaters[j]));
        }
        return r;
    }
};