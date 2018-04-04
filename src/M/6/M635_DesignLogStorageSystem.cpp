//
// Created by Andrii Cherniak on 4/3/18.
//
#include <map>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

class LogSystem {
    map<string, vector<int> > storage;
public:
    LogSystem() {

    }

    void put(int id, string timestamp) {
        storage[timestamp].push_back(id);
    }

    vector<int> retrieve(string s, string e, string gra) {
        if (gra == "Year") {
            s = s.substr(0, 4) + ":01:01:00:00:00";
            e = e.substr(0, 4) + ":12:31:23:59:59";
        } else if (gra == "Month") {
            s = s.substr(0, 7) + ":01:00:00:00";
            e = e.substr(0, 7) + ":31:23:59:59";
        } else if (gra == "Day") {
            s = s.substr(0, 10) + ":00:00:00";
            e = e.substr(0, 10) + ":23:59:59";
        } else if (gra == "Hour") {
            s = s.substr(0, 13) + ":00:00";
            e = e.substr(0, 13) + ":59:59";
        } else if (gra == "Minute") {
            s = s.substr(0, 16) + ":00";
            e = e.substr(0, 16) + ":59";
        }

        vector<int> result;
        auto lower = storage.lower_bound(s);
        if (lower == storage.end())
            return result;
        auto upper = storage.lower_bound(e);

        for (auto it = lower; it != upper; it++) {
            for (int id: it->second) result.push_back(id);
        }
        if (upper != storage.end() && upper->first >= s && upper->first <= e)
            for (int id: upper->second) result.push_back(id);

        return result;
    }
};

/**
 * Your LogSystem object will be instantiated and called as such:
 * LogSystem obj = new LogSystem();
 * obj.put(id,timestamp);
 * vector<int> param_2 = obj.retrieve(s,e,gra);
 */