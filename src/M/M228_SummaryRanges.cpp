//
// Created by Andrii Cherniak on 1/22/18.
//
#include <vector>
#include <string>

using std::vector;
using std::string;
using std::to_string;

class Solution {
    string get_range(int from_v, int to_v){
        if (from_v != to_v) return to_string(from_v) + "->" + to_string(to_v);
        else return to_string(from_v);
    }
public:
    vector<string> summaryRanges(vector<int> &nums) {
        vector<string> ranges;
        int L = nums.size();
        if (L == 0) return ranges;
        int begin = 0, end = 0;
        for (int i = 1; i < L; i++)
            if (nums[i] - nums[i-1] == 1) end ++;
            else {
                ranges.push_back(get_range(nums[begin], nums[end]));
                begin = end = i;
            }
        ranges.push_back(get_range(nums[begin], nums[end]));
        return ranges;
    }
};