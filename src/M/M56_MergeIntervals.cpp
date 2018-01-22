//
// Created by Andrii Cherniak on 1/19/18.
//


struct Interval {
    int start;
    int end;

    Interval() : start(0), end(0) {}

    Interval(int s, int e) : start(s), end(e) {}
};

#include <vector>
#include <iostream>

using std::vector;


bool operator<(const Interval &i1, const Interval &i2) { return i1.start < i2.start; }

class Solution {
public:
    vector<Interval> merge(vector<Interval> &intervals) {
        vector<Interval> answer;
        int L = intervals.size();
        if (L == 0)
            return answer;
        std::sort(intervals.begin(), intervals.end());
        answer.push_back(intervals[0]);
        int a_id = 0;
        for (int i = 1; i < L; i++) {
            if (intervals[i].start <= answer[a_id].end)
                answer[a_id].end = std::max(answer[a_id].end, intervals[i].end);
            else {
                answer.push_back(intervals[i]);
                a_id++;
            }
        }
        return answer;
    }
};