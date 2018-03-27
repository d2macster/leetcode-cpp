//
// Created by Andrii Cherniak on 3/27/18.
//
#include <vector>

using namespace std;

class Solution {
    bool safeDFS(vector<vector<int> > &graph, int v, vector<bool> &visited, vector<bool> &is_terminal) {
        if (visited[v]) return is_terminal[v];
        visited[v] = true;
        for(int next: graph[v])
            if (!safeDFS(graph, next, visited, is_terminal)) return is_terminal[v] = false;

        return is_terminal[v] = true;
    }

public:
    vector<int> eventualSafeNodes(vector<vector<int> > &graph) {
        int V = graph.size();
        vector<bool> is_terminal = vector<bool>(V, false);
        vector<int> safeNodes;
        int safeCounter = 0;

        for (int i = 0; i < V; i++) {
            is_terminal[i] = (graph[i].size() == 0);
            safeCounter++;
        }
        if (!safeCounter) return safeNodes;
        
        vector<bool> visited = vector<bool>(V, false);
        for (int i = 0; i < V; i++){
            if (!visited[i]) safeDFS(graph, i, visited, is_terminal);
        }

        for(int i = 0; i < V; i++)
            if (is_terminal[i]) safeNodes.push_back(i);
        sort(safeNodes.begin(), safeNodes.end());

        return safeNodes;
    }
};