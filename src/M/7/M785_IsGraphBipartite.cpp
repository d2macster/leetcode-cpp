//
// Created by Andrii Cherniak on 3/27/18.
//
#include <vector>

using namespace std;

class Solution {
    bool dfsColorSuccess(vector<vector<int> > &graph, int v, int cur_color, int parent, vector<int> &color) {
        if (color[v] != 0){
            if (color[v] == cur_color) return true;
            else return false;
        }
        color[v] = cur_color;
        int next_color = (cur_color == 1)?2:1;
        for (int next_v: graph[v]){
            if (next_v != parent){
                if (!dfsColorSuccess(graph, next_v, next_color, v, color)) return false;
            }
        }
        return true;
    }

public:
    bool isBipartite(vector<vector<int> > &graph) {
        int V = graph.size();
        vector<int> color = vector<int>(V, 0);
        for (int v = 0; v < V; v++) {
            if (color[v] == 0 && !dfsColorSuccess(graph, v, 1, -1, color)) return false;
        }
        return true;
    }
};