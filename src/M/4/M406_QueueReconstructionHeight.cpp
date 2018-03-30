//
// Created by Andrii Cherniak on 3/29/18.
//
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

struct comparator{
    bool operator()(pair<int, int> p1, pair<int, int>p2){
        return p1.first < p2.first || (p1.first == p2.first && p1.second > p2.second);
    }
};

class Solution {
public:
    vector<pair<int, int>> reconstructQueue(vector<pair<int, int>> &people) {
        priority_queue<pair<int, int>, vector<pair<int, int> >, comparator> q;
        for (auto p: people) q.push(p);

        vector<pair<int, int>> result;


        while (!q.empty()){
            pair<int, int> person = q.top();
            q.pop();
            result.insert(result.begin() + person.second, person);
        }


        return result;

    }
};