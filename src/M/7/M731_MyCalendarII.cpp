//
// Created by Andrii Cherniak on 4/13/18.
//
#include <map>

using namespace std;

class MyCalendarTwo {
    map<int, int> events;

public:
    MyCalendarTwo() {

    }

    bool book(int start, int end) {
        events[start]++;
        events[end]--;
        int overlap = 0;
        for (auto &e: events){
            overlap += e.second;
            if (overlap >= 3) {
                events[start]--;
                if (events[start] == 0) events.erase(start);
                events[end]++;
                if (events[end] == 0) events.erase(end);
                return false;
            }
        }
        return true;
    }
};