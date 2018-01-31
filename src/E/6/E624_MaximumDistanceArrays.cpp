//
// Created by Andrii Cherniak on 1/29/18.
//
#include <vector>
#include <algorithm>
using std::vector;

class Solution {
public:
    int maxDistance(vector<vector<int > >& arrays) {
        int m = arrays.size();
        int min_v = arrays[0][0];
        int max_v = arrays[0][arrays[0].size()-1];
        int max_diff = 0;
        int diff1, diff2;

        for (int i = 1; i < m; i++){
            diff1 = std::abs(arrays[i][arrays[i].size() - 1] - min_v);
            diff2 = std::abs(max_v - arrays[i][0]);
            max_diff = std::max(max_diff, std::max(diff1, diff2));
            min_v = std::min(min_v, arrays[i][0]);
            max_v = std::max(max_v, arrays[i][arrays[i].size() - 1]);

        }

        return max_diff;
    }
};