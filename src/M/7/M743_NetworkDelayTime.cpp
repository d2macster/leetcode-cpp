//
// Created by Andrii Cherniak on 3/26/18.
//
#include <vector>
#include <limits>
#include <queue>
#include <unordered_map>
#include <iostream>

using namespace std;

struct delay_progress {
    int node;
    int delay;
};

struct comparator {
    bool operator()(delay_progress &d1, delay_progress &d2) {
        return d1.delay > d2.delay;
    }
};

class Solution {
public:
    int networkDelayTime(vector<vector<int> > &times, int N, int K) {
        unordered_map<int, vector<vector<int> > >  edges;
        for (vector<int> &t: times) edges[t[0]].push_back(t);

        vector<int> delay = vector<int>(N + 1, INT_MAX);

        priority_queue<delay_progress, vector<delay_progress>, comparator> q;

        delay_progress kp = {K, 0};
        q.push(kp);

        while (!q.empty()) {
            delay_progress p = q.top();
            q.pop();
            if (delay[p.node] == INT_MAX){
                delay[p.node] = p.delay;
                for (vector<int> & e: edges[p.node]){
                    delay_progress pe = {e[1], p.delay+e[2]};
                    q.push(pe);
                }
            }
        }

        int max_delay = 0;
        for (int i = 1; i <= N; i++) {
            if (delay[i] == INT_MAX) return -1;
            max_delay = max(max_delay, delay[i]);
        }
        return max_delay;
    }
};