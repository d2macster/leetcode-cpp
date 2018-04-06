//
// Created by Andrii Cherniak on 4/6/18.
//
#include <unordered_map>
#include <map>
#include <list>

using namespace std;

class LFUCache {
    int N;
    int cur_size = 0;
    unordered_map<int, int> cache;
    unordered_map<int, int> access_count;
    map<int, list<int>> count_order;
    unordered_map<int, list<int>::iterator> order_map;

    void update_access(int key) {
        if (order_map.find(key) != order_map.end()) {
            count_order[access_count[key]].erase(order_map[key]);
            order_map.erase(key);
            if (count_order[access_count[key]].empty()) count_order.erase(access_count[key]);
        }
        access_count[key]++;
        count_order[access_count[key]].push_back(key);
        order_map[key] = (--count_order[access_count[key]].end());

    }

    void evict() {
        if (cur_size > N) {
            cur_size--;
            map<int, list<int>>::iterator it = count_order.begin();
            list<int> acc = (*it).second;
            int kk = *acc.begin();
            int kkCnt = access_count[kk];
            count_order[kkCnt].erase(order_map[kk]);
            order_map.erase(kk);
            if (count_order[kkCnt].empty()) count_order.erase(kkCnt);
            cache.erase(kk);
            access_count.erase(kk);

        }
    }

public:
    LFUCache(int capacity) {
        N = capacity;
    }

    int get(int key) {
        if (cache.find(key) != cache.end()) {
            update_access(key);
            return cache[key];
        } else return -1;
    }

    void put(int key, int value) {
        if (N < 1)
            return;
        if (cache.find(key) == cache.end()) cur_size++;
        evict();
        cache[key] = value;
        update_access(key);

    }
};
