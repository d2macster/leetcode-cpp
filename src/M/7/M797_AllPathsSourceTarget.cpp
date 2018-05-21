//
// Created by Andrii Cherniak on 5/21/18.
//
#include <vector>

using namespace std;

class Solution {
    void dfs(int n, vector<vector<int>> &paths, vector<int> path, vector<vector<int>> &graph){
        path.push_back(n);
        int N = graph.size();
        if (n == N-1) {
            paths.push_back(path);
            return;
        }
        for(int next: graph[n]) dfs(next, paths, path, graph);
        return;
    }
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph) {
        if (graph.empty())
            return vector<vector<int>>();
        vector<vector<int>> paths = vector<vector<int>>();
        dfs(0, paths, vector<int>(), graph);
        return paths;
    }
};