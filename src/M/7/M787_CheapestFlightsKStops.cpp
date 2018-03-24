//
// Created by Andrii Cherniak on 3/23/18.
//
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

struct path {
    int price;
    int city;
    int hops;
};

struct comparator {
    bool operator()(const path &p1, const path &p2) {
        return p1.price > p2.price;
    }
};

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int K) {
        K++;

        unordered_map<int, vector<vector<int>> > departures;
        for (vector<int> flight: flights){
            departures[flight[0]].push_back(flight);
        }

        priority_queue<path, vector<path>, comparator> q;
        path p = {0, src, 0};
        q.push(p);

        while (!q.empty()){
            path p = q.top();
            q.pop();
            if (p.city == dst && p.hops <= K) return p.price;
            if (p.city != dst && p.hops < K){
                for (vector<int> flight : departures[p.city]){
                    path next_p = {flight[2] + p.price, flight[1], p.hops+1};
                    q.push(next_p);
                }
            }
        }

        return -1;

    }
};