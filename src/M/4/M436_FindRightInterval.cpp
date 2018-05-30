//
// Created by Andrii Cherniak on 5/30/18.
//
#include <vector>
#include <map>

using namespace std;

struct Interval {
    int start;
    int end;

    Interval() : start(0), end(0) {}

    Interval(int s, int e) : start(s), end(e) {}
};

bool f(const Interval &i1, const Interval &i2) {
    return (i1.start <= i2.start);
}

class Solution {
public:
    vector<int> findRightInterval(vector<Interval> &intervals) {
        if (intervals.empty())
            return vector<int>();
        int L = intervals.size();
        vector<int> result = vector<int>(L, -1);
        map<int, int> m;
        for (int i = 0; i < L; i++) {
            int key = intervals[i].start;
            if (m.find(key) == m.end())
                m[key] = i;
        }
        for (int i = 0; i < L; i++){
            int key = intervals[i].end;
            auto it = m.lower_bound(key);
            if (it != m.end()) result[i] = it->second;
        }
        return result;
    }
};