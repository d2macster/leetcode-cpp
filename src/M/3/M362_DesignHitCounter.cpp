//
// Created by Andrii Cherniak on 4/3/18.
//
#include <map>
#include <iostream>

using namespace std;

class HitCounter {
    map<int, int> counter;
public:
    /** Initialize your data structure here. */
    HitCounter() {

    }

    void clear(int timestamp) {
        int cutoff = timestamp - 300;
        cout << "first " << counter.begin()->first << " cutoff " << cutoff << endl;
        while (!counter.empty() && counter.begin()->first <= cutoff) counter.erase(counter.begin());
    }

    /** Record a hit.
        @param timestamp - The current timestamp (in seconds granularity). */
    void hit(int timestamp) {
        clear(timestamp);
        counter[timestamp]++;
    }

    /** Return the number of hits in the past 5 minutes.
        @param timestamp - The current timestamp (in seconds granularity). */
    int getHits(int timestamp) {
        clear(timestamp);
        int sum = 0;
        for (int ts = timestamp - 300; ts <= timestamp; ts++) {
            if (counter.find(ts) != counter.end())
            sum += counter[ts];
        }
        return sum;
    }
};
