//
// Created by Andrii Cherniak on 4/13/18.
//
#include <map>

using namespace std;

class MyCalendar {
    map<int, int> calendar;
public:
    MyCalendar() {

    }

    bool book(int start, int end) {
        if (calendar.empty()){
            calendar[start] = end;
            return true;
        }
        map<int, int>::iterator it = calendar.lower_bound(start);
        if (it != calendar.end() && it->first < end) return false;
        if (it != calendar.begin()){
            it--;
            if (it->second > start) return false;
        }
        calendar[start] = end;
        return true;

    }
};