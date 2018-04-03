//
// Created by Andrii Cherniak on 4/3/18.
//
#include <queue>
#include <iostream>
using namespace std;

class HitCounter {
    queue<int> q;
public:
    /** Initialize your data structure here. */
    HitCounter() {

    }

    void clear(int timestamp) {
        int cutoff = timestamp - 300;
        cout << "front " << q.front() << " cutoff " << cutoff << endl;
        while (!q.empty() && q.front() <= cutoff) {
            q.pop();
            cout << "front " << q.front() << " cutoff " << cutoff << endl;
        }

    }

    /** Record a hit.
        @param timestamp - The current timestamp (in seconds granularity). */
    void hit(int timestamp) {
        q.push(timestamp);
        clear(timestamp);

    }

    /** Return the number of hits in the past 5 minutes.
        @param timestamp - The current timestamp (in seconds granularity). */
    int getHits(int timestamp) {
        clear(timestamp);
        return q.size();
    }
};
