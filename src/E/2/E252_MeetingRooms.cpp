//
// Created by Andrii Cherniak on 3/1/18.
//
#include <vector>
#include <algorithm>
#include <limits>

using std::vector;

struct Interval {
    int start;
    int end;

    Interval() : start(0), end(0) {}

    Interval(int s, int e) : start(s), end(e) {}
};

bool operator<(const Interval &a, const Interval &b) {
    return a.start < b.start;
}

class Solution {
public:
    bool canAttendMeetings(vector<Interval> &intervals) {
        int L = intervals.size();
        if (L <= 1) return true;
        std::sort(intervals.begin(), intervals.end());
        int ends = INT_MIN;
        for (auto i: intervals){
            if (i.start < ends) return false;
            ends = std::max(ends, i.end);
        }
        return true;
    }
};