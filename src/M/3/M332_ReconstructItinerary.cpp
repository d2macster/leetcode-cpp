//
// Created by Andrii Cherniak on 3/26/18.
//
#include <vector>
#include <string>
#include <unordered_map>
#include <queue>

using namespace std;

class Solution {
    unordered_map<string, priority_queue<string, vector<string>, greater<string> > > flights;
    vector<string> itinerary;

    void helper(string airport) {
        auto &q = flights[airport];
        while (!q.empty()) {
            string next = q.top();
            q.pop();
            helper(next);
        }
        itinerary.push_back(airport);
    }

public:
    vector<string> findItinerary(vector<pair<string, string> > tickets) {
        for (pair<string, string> &t: tickets)
            flights[t.first].push(t.second);

        helper("JFK");
        reverse(itinerary.begin(), itinerary.end());
        return itinerary;
    }
};