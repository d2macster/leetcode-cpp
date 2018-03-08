//
// Created by Andrii Cherniak on 3/7/18.
//
#include <algorithm>
#include <vector>

using std::vector;

struct Interval {
    int start;
    int end;

    Interval() : start(0), end(0) {}

    Interval(int s, int e) : start(s), end(e) {}
};

bool operator<(const Interval &i1, const Interval &i2) {
    return (i1.start < i2.start);
}

class Solution {
public:
    int minMeetingRooms(vector<Interval> &intervals) {
        int L = intervals.size();
        if (L <= 1)
            return L;
        vector<int> meeting_starts = vector<int>(L);
        vector<int> meeting_ends = vector<int>(L);
        for (int i = 0; i < L; i++) {
            meeting_starts[i] = intervals[i].start;
            meeting_ends[i] = intervals[i].end;
        }
        std::sort(meeting_starts.begin(), meeting_starts.end());
        std::sort(meeting_ends.begin(), meeting_ends.end());
        int rooms = 0, maxRooms = 0;
        int starts_id = 0, ends_id = 0;
        while (starts_id < L && ends_id < L){
            if (meeting_starts[starts_id] < meeting_ends[ends_id]){
                rooms ++;
                maxRooms = std::max(maxRooms, rooms);
                starts_id++;
            } else{
                rooms--;
                ends_id++;
            }
        }
        return maxRooms;

    }
};