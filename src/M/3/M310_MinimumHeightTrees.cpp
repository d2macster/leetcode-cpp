//
// Created by Andrii Cherniak on 3/27/18.
//
#include <vector>
#include <limits>
#include <iostream>

using namespace std;

class Solution {
    void bfs(vector<vector<int> > &graph, int v, int parent, int d, vector<int> &distance) {
        distance[v] = d;
        for (int next: graph[v])
            if (next != parent) bfs(graph, next, v, d + 1, distance);
    }

    void explorePath(vector<vector<int> > &graph, int v, int parent, vector<int> &path, vector<int> &best_path){
        path.push_back(v);
        if (path.size() > best_path.size()) best_path = path;
        for (int next: graph[v])
            if (next != parent) explorePath(graph, next, v, path, best_path);
        path.erase(path.end()-1);
    }



public:
    vector<int> findMinHeightTrees(int n, vector<pair<int, int> > &edges) {
        vector<int> roots;

        vector<vector<int> > graph = vector<vector<int> >(n, vector<int>());
        for (auto e: edges) {
            graph[e.first].push_back(e.second);
            graph[e.second].push_back(e.first);
        }
        vector<int> distance = vector<int>(n, 0);
        bfs(graph, 0, -1, 0, distance);

        int maxD = 0;
        int maxDnode = 0;
        for (int i = 0; i < n; i++) {
            if (distance[i] > maxD) {
                maxD = distance[i];
                maxDnode = i;
            }
        }
        vector<int> path, best_path;

        explorePath(graph, maxDnode, -1, path, best_path);
        int pL = best_path.size();
        if (pL % 2 == 1) roots.push_back(best_path[pL/2]);
        else{
            roots.push_back(best_path[(pL-1)/2]);
            roots.push_back(best_path[pL/2]);
        }

        return roots;
    }
};