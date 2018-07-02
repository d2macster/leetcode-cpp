//
// Created by Andrii Cherniak on 7/2/18.
//
#include <vector>

using namespace std;

struct Interval {
    int start;
    int end;

    Interval() : start(0), end(0) {}

    Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
    void addInterval(vector<Interval> &result, Interval i){
        cout << i.start << " " << i.end << endl;
        if (result.empty()) result.push_back(i);
        else{
            int L = result.size();
            if (result[L-1].end >= i.start) result[L-1].end = max(result[L-1].end, i.end);
            else result.push_back(i);
        }
    }
public:
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        if (intervals.empty()){
            intervals.push_back(newInterval);
            return intervals;
        }

        int L = intervals.size();

        if (newInterval.start > intervals[L-1].start){
            addInterval(intervals, newInterval);
            return intervals;
        }

        vector<Interval> result;
        for(int i = 0; i < L; i++){
            if (intervals[i].start < newInterval.start) addInterval(result, intervals[i]);
            else {
                addInterval(result, newInterval);
                addInterval(result, intervals[i]);
            }
        }
        return result;
    }
};