//
// Created by Andrii Cherniak on 4/13/18.
//
#include <set>
#include <unordered_map>

using namespace std;

class MyCalendarTwo {
    set<int> event_list;
    unordered_map<int, int> start_counter, end_counter;

    bool add_interval(int start, int end) {
        start_counter[start]++;
        end_counter[end]++;
        event_list.insert(start);
        event_list.insert(end);
        int overlap = 0;

        for (auto e: event_list) {
            overlap += start_counter[e];
            overlap -= end_counter[e];
            if (overlap > 2) return false;
        }

        return true;
    }

    void remove_interval(int start, int end) {
        start_counter[start]--;
        end_counter[end]--;
    }

public:
    MyCalendarTwo() {

    }

    bool book(int start, int end) {
        if (add_interval(start, end)) return true;
        else{
            remove_interval(start, end);
            return false;
        }
    }
};