//
// Created by Andrii Cherniak on 3/26/18.
//
#include <vector>
#include <string>
#include <unordered_map>
#include <multiset>

using namespace std;

class Solution {
    unordered_map<string, multiset<string> > flights;
    vector<string> itinerary;

    void explore(string airport){
        while (flights[airport].size()){
            string next = *flights[airport].begin();
            flights[airport].erase(flights[airport].begin());
            explore(next);
        }
        itinerary.push_back(airport);
    }

public:
    vector<string> findItinerary(vector<pair<string, string> > tickets) {
        for (pair<string, string> &t: tickets)
            flights[t.first].insert(t.second);

        explore("JFK");
        reverse(itinerary.begin(), itinerary.end());
        return itinerary;
    }
};