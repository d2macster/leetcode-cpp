//
// Created by Andrii Cherniak on 4/23/18.
//
#include <map>
using namespace std;

class MyCalendarThree {
    map<int, int> calendar;
public:
    MyCalendarThree() {

    }

    int book(int start, int end) {
        calendar[start]++;
        calendar[end]--;
        int overlap = 0;
        int maxOverlap = 0;
        for (auto it = calendar.begin(); it != calendar.end(); it++){
            overlap += it->second;
            maxOverlap = max(maxOverlap, overlap);
        }
        return maxOverlap;
    }
};