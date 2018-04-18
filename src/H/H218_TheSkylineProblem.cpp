//
// Created by Andrii Cherniak on 4/17/18.
//
#include <vector>
#include <map>
#include <set>
#include <iostream>
#include <queue>
using namespace std;

struct building{
    int Li;
    int Ri;
    int Hi;
};

struct comparator{
    bool operator()(building & b1, building & b2){
        return b1.Hi < b2.Hi;
    }
};

class Solution {
public:
    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
        vector<pair<int, int>> result;
        priority_queue<building, vector<building>, comparator> q;
        map<int, vector<building>> walls;
        set<int> points;

        for (vector<int> &b: buildings){
            building bb = {b[0], b[1], b[2]};
            walls[b[0]].push_back(bb);
            points.insert(b[0]);
            points.insert(b[1]);
        }

        int prev_y = 0;
        int cur_y = 0;

        for (int x: points){
            if (walls.find(x) != walls.end()){
                for (building & b: walls[x]) q.push(b);
            }
            while (!q.empty() && q.top().Ri <= x) q.pop();
            cur_y = (q.empty())?0:q.top().Hi;
            if (cur_y != prev_y) result.push_back(make_pair(x, cur_y));
            prev_y = cur_y;
        }


        return result;

    }
};