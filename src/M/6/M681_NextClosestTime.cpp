//
// Created by Andrii Cherniak on 3/21/18.
//
#include <string>
#include <set>
#include <iostream>
#include <limits>


using namespace std;

class Solution {
    int next_value(int cur_val, set<int> &digits, int max_val) {
        int next = INT_MAX;
        for (int d1: digits)
            for (int d2: digits){
                int v = 10 * d1 + d2;
                if (v > cur_val && v <= max_val) next = min(next, v);
            }

        return (next == INT_MAX)?cur_val:next;
    }

public:
    string nextClosestTime(string time) {
        set<int> digits;
        for (int t_id: (int[]) {0, 1, 3, 4})
            digits.insert(time[t_id] - '0');
        if (digits.size() == 1) return time;
        int minutes = 10 * (time[3] - '0') + (time[4] - '0');
        int next_minutes = next_value(minutes, digits, 59);
        if (next_minutes > minutes) {
            time[3] = ('0' + next_minutes / 10);
            time[4] = ('0' + next_minutes % 10);
            return time;
        }
        int hours = 10 * (time[0] - '0') + (time[1] - '0');
        int next_hours = next_value(hours, digits, 23);
        if (next_hours > hours) {
            time[0] = ('0' + next_hours / 10);
            time[1] = ('0' + next_hours % 10);
        } else
            time[0] = time[1] = ('0' + *digits.begin());
        time[3] = time[4] = ('0' + *digits.begin());

        return time;
    }
};