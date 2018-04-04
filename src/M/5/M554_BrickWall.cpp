//
// Created by Andrii Cherniak on 4/4/18.
//
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        // x coord, # of edges
        unordered_map<int , int> edges;
        int ww = 0;
        for(vector<int> & row: wall){
            int x = 0;
            for (int w: row){
                x += w;
                edges[x]++;
            }
            ww = max(ww, x);
        }
        int wL = wall.size();
        int maxEdges = 0;
        for (auto it: edges) if (it.first != ww) maxEdges = max(maxEdges, it.second);
        return wL - maxEdges;

    }
};