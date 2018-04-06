//
// Created by Andrii Cherniak on 4/6/18.
//
#include <unordered_map>
#include <list>

using namespace std;

class LRUCache {
    int N;
    unordered_map<int, int> cache;
    list<int> access_history;
    unordered_map<int , list<int >::iterator> access_map;
public:
    LRUCache(int capacity) {
        N = capacity;
    }

    int get(int key) {
        if (cache.find(key) != cache.end()) {
            access_history.erase(access_map[key]);
            access_history.push_back(key);
            access_map[key] = (--access_history.end());
            return cache[key];
        }
        return -1;
    }

    void put(int key, int value) {
        cache[key] = value;
        if (access_map.find(key) != access_map.end()) access_history.erase(access_map[key]);
        access_history.push_back(key);
        access_map[key] = (--access_history.end());
        if (access_history.size() > N){
            int kk = *access_history.begin();
            access_history.erase(access_history.begin());
            access_map.erase(kk);
            cache.erase(kk);
        }
    }
};