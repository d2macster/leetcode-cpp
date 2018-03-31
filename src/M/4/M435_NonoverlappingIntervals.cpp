//
// Created by Andrii Cherniak on 3/30/18.
//
#include <vector>
#include <iostream>

using namespace std;

bool compare(const Interval &i1, const Interval &i2) {
    return i1.start < i2.start;
}


struct Interval {
    int start;
    int end;

    Interval() : start(0), end(0) {}

    Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
public:
    int eraseOverlapIntervals(vector<Interval> &intervals) {
        int N = intervals.size();
        if (N <= 1)
            return 0;
        sort(intervals.begin(), intervals.end(), compare);
        Interval prev = intervals[0];
        int counter = 0;
        for (int i = 1; i < N; i++) {
            Interval next = intervals[i];
            if (next.start >= prev.end){
                prev = next;
            }else {
                if (next.end <= prev.end) prev = next;
                counter++;
            }
        }
        return counter;
    }
};