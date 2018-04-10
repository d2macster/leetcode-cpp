//
// Created by Andrii Cherniak on 4/10/18.
//
#include <unordered_map>
#include <map>
#include <set>
#include <string>
#include <iostream>

using namespace std;

class AllOne {
    unordered_map<string, int> counter;
    map<int, set<string>> grouped_keys;
public:
    /** Initialize your data structure here. */
    AllOne() {

    }

    /** Inserts a new key <Key> with value 1. Or increments an existing key by 1. */
    void inc(string key) {
        if (counter.find(key) == counter.end()) {
            counter[key] = 1;
            grouped_keys[1].insert(key);
        } else {
            grouped_keys[counter[key]].erase(key);
            if (grouped_keys[counter[key]].empty()) grouped_keys.erase(counter[key]);
            counter[key]++;
            grouped_keys[counter[key]].insert(key);
        }
        
    }

    /** Decrements an existing key by 1. If Key's value is 1, remove it from the data structure. */
    void dec(string key) {

        if (counter.find(key) != counter.end()) {
            grouped_keys[counter[key]].erase(key);
            if (grouped_keys[counter[key]].empty()) grouped_keys.erase(counter[key]);

            counter[key]--;
            if (counter[key] < 1) counter.erase(key);
            else grouped_keys[counter[key]].insert(key);

        }
    }

    /** Returns one of the keys with maximal value. */
    string getMaxKey() {
        if (grouped_keys.empty()) return "";
        map<int, set<string>>::iterator it = (--grouped_keys.end());
        return *(it->second.begin());
    }

    /** Returns one of the keys with Minimal value. */
    string getMinKey() {
        if (grouped_keys.empty()) return "";
        map<int, set<string>>::iterator it = grouped_keys.begin();
        return *(it->second.begin());
    }
};