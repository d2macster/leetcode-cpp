//
// Created by Andrii Cherniak on 4/5/18.
//
#include <vector>
#include <string>
using namespace std;

class Solution {
    void processRange(long l, long r, vector<string> &ranges){
        long diff = r - l;
        if (diff == 2) ranges.push_back(to_string(l + 1L));
        if (diff > 2)ranges.push_back(to_string(l+1L) + "->" + to_string(r-1L));
    }
public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        vector<string> ranges;
        long l = long(lower)-1L, r = long(lower)-1L;
        for (int n: nums){
            l = long(r);
            r = long(n);
            processRange(l, r, ranges);
        }
        l = long(r);
        r = long(upper)+1L;
        processRange(l, r, ranges);

        return ranges;
    }
};