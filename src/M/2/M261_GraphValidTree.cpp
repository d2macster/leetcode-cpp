//
// Created by Andrii Cherniak on 3/26/18.
//
#include <vector>

using namespace std;

class Solution {
    bool hasCycles(int node, int parent, vector<vector<int> > &graph, vector<bool> &visited) {
        if (visited[node]) return true;
        visited[node] = true;
        for (int next : graph[node]) {
            if (next != parent && hasCycles(next, node, graph, visited)) return true;
        }

        return false;
    }

public:
    bool validTree(int n, vector<pair<int, int>> &edges) {

        vector<vector<int> > graph = vector<vector<int> >(n, vector<int>());
        vector<bool> visited = vector<bool>(n, false);

        for (pair<int, int> e: edges) {
            graph[e.first].push_back(e.second);
            graph[e.second].push_back(e.first);
        }

        if (hasCycles(0, -1, graph, visited)) return false;
        for (int i = 0; i < n; i++) if (!visited[i]) return false;


        return true;
    }
};